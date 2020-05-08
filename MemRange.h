#ifndef MEMRANGE_H
#define MEMRANGE_H

#include "Process.h"

class MemRange
{
private:
  long long int start_; // start range of memory for process
  long long int end_;   // end range of memory for process
  Process process_;     // process in memory

public:
  MemRange();                                                                             // default constructor
  MemRange(const long long int &start, const long long int &end, const Process &process); // parameterized constructor

  void setStart(const long long int &start); // set start range
  void setEnd(const long long int &end);     // set end range
  void setProcess(const Process &process);   // set process
  long long int getStart() const;            // @return start range
  long long int getEnd() const;              // @return end range
};

#endif // MEMRANGE_H