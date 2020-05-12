/**
 * Author: Shania Dhani
 * Date Modified May 12, 2020
 * 
 * MemBlock is the foundational units that represent processes in memory.
 */

#include "MemBlock.hpp"

// default constructor
MemBlock::MemBlock() {}

// parameterized constructor
MemBlock::MemBlock(const long long int &start, const long long int &end, const long long int &pid,
                   const long long int &memory_chunk, const bool active)
{
  start_ = start;
  end_ = end;
  pid_ = pid;
  memory_chunk_ = memory_chunk;
  active_ = active;
}

// set start range
void MemBlock::setStart(const long long int &start)
{
  start_ = start;
}

// set end range
void MemBlock::setEnd(const long long int &end)
{
  end_ = end;
}

// set memory_chunk size
void MemBlock::setMemoryChunk(const long long int &memory_chunk)
{
  memory_chunk_ = memory_chunk;
}

// set pid
void MemBlock::setPID(const long long int &pid)
{
  pid_ = pid;
}

// set active
void MemBlock::setActive(const bool &is_active)
{
  active_ = is_active;
}

// @return start range
long long int MemBlock::start() const
{
  return start_;
}

// @return end range
long long int MemBlock::end() const
{
  return end_;
}

// @return pid
long long int MemBlock::pid() const
{
  return pid_;
}

// @return process memory chunk size
long long int MemBlock::memoryChunk() const
{
  return memory_chunk_;
}

// @return process in memory activity
bool MemBlock::active() const
{
  return active_;
}
