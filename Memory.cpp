#include "Memory.h"
#include <iomanip>

Memory::Memory() {}

Memory::Memory(const long long int &memory_size)
{
  memory_size_ = memory_size;
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
std::list<MemRange> Memory::getContiguousMemory() const
{
  return continguous_memory_;
}

// print out memory snapshot
void Memory::printMemory() const
{
  const char separator = ' ';
  const int pidWidth = 6;
  const int rangeWidth = 16;

  std::cout << std::left << std::setw(pidWidth) << std::setfill(separator) << "PID" << std::endl;
  std::cout << std::left << std::setw(rangeWidth) << std::setfill(separator) << "MemRange" << std::endl;

  for (const auto &mem_range : continguous_memory_)
  {
    std::cout << std::left << std::setw(pidWidth) << std::setfill(separator)
              << mem_range.getProcess().getPID() << std::endl;

    std::cout << std::left << std::setw(rangeWidth) << std::setfill(separator)
              << mem_range.getStart() << "-" << mem_range.getEnd() << std::endl;
  }
}