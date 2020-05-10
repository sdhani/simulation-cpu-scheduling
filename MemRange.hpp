#ifndef MEMRANGE_H
#define MEMRANGE_H

#include "Process.hpp"

class MemRange
{
private:
  long long int start_; // start range of memory for process
  long long int end_;   // end range of memory for process
  Process process_;     // process in memory
  bool active_;         // is process terminated, release memory

public:
  MemRange();                                                                             // default constructor
  MemRange(const long long int &start, const long long int &end, const Process &process); // parameterized constructor

  void setStart(const long long int &start); // set start range
  void setEnd(const long long int &end);     // set end range
  void setProcess(const Process &process);   // set process
  void setActive(const bool &is_active);     // set active
  long long int getStart() const;            // @return start range
  long long int getEnd() const;              // @return end range
  Process getProcess() const;                // @return process
  bool isActive() const;                     // get process activity
};

#endif // MEMRANGE_H