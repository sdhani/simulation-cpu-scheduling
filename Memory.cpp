#include "Memory.hpp"

struct MemBlock
{
  long long int start_;
  long long int end_;
  long long int pid_;
  long long int memory_chunk_;
  bool active_;
};

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

// @return memory list
// std::vector<MemBlock> Memory::getContiguousMemory() const
// {
//   return continguous_memory_;
// }

// consolidate consecutive memory holes into one
void Memory::consolidateMemoryChunks()
{
  bool seenHole = false;            /* tracks if seen a hole */
  unsigned long long int hole = -1; /* tracks index of last hole */
  for (unsigned long long i = 0; i < continguous_memory_.size(); i++)
  {
    MemBlock &m = continguous_memory_[i];

    if (!m.active_ && !seenHole)
    {
      seenHole = true;
      hole = i;
    }
    else if (seenHole && !m.active_)
    {
      if (hole == i - 1)
      {
        continguous_memory_[hole].end_ = m.end_;
        continguous_memory_[hole].memory_chunk_ += m.memory_chunk_;
        continguous_memory_.erase(continguous_memory_.begin() + i);
      }
      else
      {
        hole = i;
      }
    }
    if (m.start_ >= m.end_)
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
    for (unsigned long long i = 0; i < continguous_memory_.size(); i++)
    {
      MemBlock &m = continguous_memory_[i];
      if (!m.active_ && m.memory_chunk_ >= p_size)
      {
        int new_end = 0;
        if (i == 0)
        {
          new_end = (m.start_ + p_size) - 1;
        }
        else
        {
          new_end = (m.start_ + p_size);
        }
        MemBlock new_m = {m.start_ + 1, new_end, p.getPID(), p_size, true};

        continguous_memory_[i].start_ = new_end + 1; // Shift start of memory hole to end of new process
        continguous_memory_[i].memory_chunk_ = continguous_memory_[i].end_ - new_end;
        continguous_memory_.insert(continguous_memory_.begin() + i, new_m);

        free_memory_ -= p_size; // allocate memory
        return true;
      }
    }

    /* Append to front of memory */
    if (continguous_memory_.empty())
    {
      MemBlock new_m = {0, (p_size + -1), p.getPID(), p_size, true};
      continguous_memory_.push_back(new_m);
      free_memory_ -= p_size; // allocate memory
      return true;
    }
    /* Append to the end of memory */
    else if ((memory_size_ - continguous_memory_.back().end_) >= p_size)
    {
      int end = continguous_memory_.back().end_; // end of last process in memory
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
  for (unsigned long long i = 0; i < continguous_memory_.size(); i++)
  {
    if (continguous_memory_[i].pid_ == p.getPID())
    {
      continguous_memory_[i].active_ = false; /* Process Terminated */
      free_memory_ += continguous_memory_[i].memory_chunk_;
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
    std::cout << "0-" << std::to_string(memory_size_) << "| EMPTY" << std::endl;
  }

  for (auto &m : continguous_memory_)
  {
    std::cout << m.start_ << "-" << m.end_ << "| " << (m.active_ ? printPIDM(m.pid_) : "EMPTY") << std::endl;
  }
}