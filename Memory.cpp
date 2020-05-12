/**
 * Author: Shania Dhani
 * Date Modified May 12, 2020
 * 
 * Memory controls all memory logic in the simulation including the allocation
 * of and releasing of process memory. It also addresses memory holes. It follows
 * a "First-Fit" approach to handling process memory allocation in "continguous memory."
 */

#include "Memory.hpp"

Memory::Memory() {}

Memory::Memory(const long long int &memory_size)
{
  memory_size_ = memory_size;
  free_memory_ = memory_size;
}

// sets size of RAM memory
void Memory::setMemorySize(const long long int &memory_size)
{
  memory_size_ = memory_size;
}

// @return size of RAM memory
long long int Memory::getMemorySize() const
{
  return memory_size_;
}

// consolidate consecutive memory holes into one
void Memory::consolidateMemoryChunks()
{
  bool seenHole = false;            /* tracks if seen a hole */
  unsigned long long int hole = -1; /* tracks index of last hole */
  for (unsigned long long int i = 0; i < continguous_memory_.size(); i++)
  {
    MemBlock &m = continguous_memory_[i];

    if (!m.active() && !seenHole)
    {
      seenHole = true;
      hole = i;
    }
    else if (seenHole && !m.active())
    {
      if (hole == i - 1)
      {
        continguous_memory_[hole].setEnd(m.end());
        continguous_memory_[hole].setMemoryChunk(continguous_memory_[hole].memoryChunk() + m.memoryChunk());
        continguous_memory_.erase(continguous_memory_.begin() + i);
      }
      else
      {
        hole = i;
      }
    }
    if (m.start() >= m.end())
    {
      continguous_memory_.erase(continguous_memory_.begin() + i);
    }
  }
}

// @return true if add process to memory is successful
bool Memory::addProcessToMemory(const Process &p)
{
  consolidateMemoryChunks(); // consolidate memory chunks

  long long int p_size = p.getMemorySize();
  if (free_memory_ >= p_size)
  {
    for (unsigned long long int i = 0; i < continguous_memory_.size(); i++)
    {
      MemBlock &m = continguous_memory_[i];
      if (!m.active() && m.memoryChunk() >= p_size)
      {
        long long int new_end = 0;
        if (i == 0)
        {
          new_end = (m.start() + p_size) - 1;
        }
        else
        {
          new_end = (m.start() + p_size) - 1;
        }
        MemBlock new_m = {m.start(), new_end, p.getPID(), p_size, true};

        continguous_memory_[i].setStart(new_end + 1); // Shift start of memory hole to end of new process
        continguous_memory_[i].setMemoryChunk(continguous_memory_[i].end() - new_end);
        continguous_memory_.insert(continguous_memory_.begin() + i, new_m);

        free_memory_ -= p_size; // allocate memory
        return true;
      }
    }

    /* Append to front of memory */
    if (continguous_memory_.empty())
    {
      MemBlock new_m = {0, (p_size - 1), p.getPID(), p_size, true};
      continguous_memory_.push_back(new_m);
      free_memory_ -= p_size; // allocate memory
      return true;
    }
    /* Append to the end of memory */
    else if ((memory_size_ - continguous_memory_.back().end()) >= p_size)
    {
      long long int end = continguous_memory_.back().end(); // end of last process in memory
      MemBlock new_m = {end + 1, (end + p_size), p.getPID(), p_size, true};
      continguous_memory_.push_back(new_m);
      free_memory_ -= p_size; // allocate memory
      return true;
    }
  }

  std::cout << "Not enough memory to add new process." << std::endl;
  return false;
}

// @return true if remove process from memory is successful
bool Memory::removeProcessFromMemory(const Process &p)
{
  for (unsigned long long int i = 0; i < continguous_memory_.size(); i++)
  {
    if (continguous_memory_[i].pid() == p.getPID())
    {
      continguous_memory_[i].setActive(false); /* Process Terminated */
      free_memory_ += continguous_memory_[i].memoryChunk();
      consolidateMemoryChunks(); // consolidate memory chunks
      return true;
    }
  }
  return false; /* process does not exist */
}

// helper print PID function
std::string printPIDM(const long long int &pid)
{
  return "P" + std::to_string(pid) + " ";
}

// print out memory snapshot
void Memory::printMemory()
{
  consolidateMemoryChunks(); // consolidate memory chunks
  if (continguous_memory_.empty())
  {
    std::cout << "   0-" << std::to_string(memory_size_) << "| EMPTY" << std::endl;
  }

  for (auto &m : continguous_memory_)
  {
    std::cout << "   " << m.start() << "-" << m.end() << "| " << (m.active() ? printPIDM(m.pid()) : "EMPTY") << std::endl;
  }
}