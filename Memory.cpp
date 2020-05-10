#include "Memory.hpp"

struct MemBlock
{
  int start_;
  int end_;
  int pid_;
};

Memory::Memory() {}

Memory::Memory(const long long int &memory_size)
{
  memory_size_ = memory_size;
  free_memory_ = memory_size;
}

// sets size of RAM memory
void Memory::setMemorySize(const int &memory_size)
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

// @return true if add process to memory is successful
bool Memory::addProcessToMemory(const Process &p)
{
  int p_size = p.getMemorySize();
  if (free_memory_ >= p_size)
  {
    for (unsigned i = 0; i < continguous_memory_.size(); i++)
    {
      MemBlock m = continguous_memory_[i];
      if (!m.active_ && m.memory_chunk_ >= p_size)
      {
        int new_end = (m.start_ + p_size);
        MemBlock new_m = {m.start_, new_end, p.getPID(), p_size, true};

        continguous_memory_[i].start_ = new_end; // Shift start of memory hole to end of new process
        continguous_memory_[i].memory_chunk_ = continguous_memory_[i].end_ - new_end;
        continguous_memory_.insert(continguous_memory_.begin() + i, new_m);

        free_memory_ -= p_size; // allocate memory
        return true;
      }
    }

    /* Append to front of memory */
    if (continguous_memory_.empty() && free_memory_ >= p_size)
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
      MemBlock new_m = {end, (end + p_size), p.getPID(), p_size, true};
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
  for (unsigned i = 0; i < continguous_memory_.size(); i++)
  {
    if (continguous_memory_[i].pid_ == p.getPID())
    {
      continguous_memory_[i].active_ = false; /* Process Terminated */
      free_memory_ += continguous_memory_[i].memory_chunk_;
      return true;
    }
  }
  return false; /* process does not exist */
}

// print out memory snapshot
void Memory::printMemory() const
{
  if (continguous_memory_.empty())
  {
    std::cout << "memory empty" << std::endl;
  }

  for (auto &m : continguous_memory_)
  {
    std::cout << m.pid_ << "|  "
              << m.start_ << "-" << m.end_ << "| " << (m.active_ ? "A" : "EMPTY") << std::endl;
  }
}

// // @return true if add process to memory is successful
// bool Memory::addProcessToMemory(const Process &p)
// {
//   for (unsigned int i = 0; i < continguous_memory_.size(); i++)
//   {
//     MemRange &m = continguous_memory_[i];
//     if (!m.isActive() && (m.getProcess().getMemorySize() >= p.getMemorySize()))
//     {
//       MemRange new_process;
//       new_process.setStart(m.getStart());                   /* set new process start to start of memory hole */
//       new_process.setEnd(m.getStart() + p.getMemorySize()); /* set new process end to start + new process's size */
//       new_process.setActive(true);

//       /* insert new process into vector of continguous memory */
//       continguous_memory_.insert(continguous_memory_.begin() + i, new_process);
//       memory_size_ -= p.getMemorySize();

//       if (m.getProcess().getMemorySize() != p.getMemorySize()) /* if memory hole remains */
//       {
//         m.setStart(new_process.getEnd()); /* its end range stays the same */
//       }
//       return true;
//     }
//     else if ((i == continguous_memory_.size() - 1) || continguous_memory_.size()) /* if no memory holes big enough for new process, try appending it to end */
//     {
//       if ((memory_size_ - m.getEnd()) >= p.getMemorySize())
//       {
//         MemRange new_process;
//         new_process.setStart(m.getEnd());                   /* set new process start to start of memory hole */
//         new_process.setEnd(m.getEnd() + p.getMemorySize()); /* set new process end to start + new process's size */
//         new_process.setActive(true);

//         /* insert new process into vector of continguous memory */
//         continguous_memory_.insert(continguous_memory_.begin() + i, new_process);
//         memory_size_ -= p.getMemorySize();
//         return true;
//       }
//       else
//       {
//         std::cout << "add fail, not enough memory" << std::endl;
//         return false;
//       }
//     }
//   }

//   if (continguous_memory_.empty() && (memory_size_ >= p.getMemorySize())) /* if no fit between processes in memory, try appending it to end */
//   {
//     MemRange new_process;
//     new_process.setStart(0);                    /* set new process start to start of memory hole */
//     new_process.setEnd(-1 + p.getMemorySize()); /* set new process end to start + new process's size */
//     new_process.setActive(true);

//     /* insert new process into vector of continguous memory */
//     continguous_memory_.push_back(new_process);
//     memory_size_ -= p.getMemorySize();
//     return true;
//   }
//   else
//   {
//     std::cout << "add fail 1" << std::endl;
//     return false;
//   }
//   return true; /* Added in the loop, check memory before add */
// }