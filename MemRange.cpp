#include "MemRange.h"

// default constructor
MemRange::MemRange() {}

// parameterized constructor
MemRange::MemRange(const long long int &start, const long long int &end, const Process &process)
{
  start_ = start;
  end_ = end;
  process_ = process;
}

// set start range
void MemRange::setStart(const long long int &start)
{
  start_ = start;
}

// set end range
void MemRange::setEnd(const long long int &end)
{
  end_ = end;
}

// set process
void MemRange::setProcess(const Process &process)
{
  process_ = process;
}

// @return start range
long long int MemRange::getStart() const
{
  return start_;
}

// @return end range
long long int MemRange::getEnd() const
{
  return end_;
}