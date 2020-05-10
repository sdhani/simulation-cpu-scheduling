#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

class Process
{
private:
  std::string process_type_ = ""; /* 'C', Common Process or 'RT', RT-process */
  long long int memory_size_;     /* In the case that process takes up entire memory */
  int pid_;                       /* Don't reassign PID's */

public:
  Process();                                                                        // default constructor
  Process(const std::string &process_type, const int &memory_size, const int &pid); // parameterized constructor

  void setProcessType(const std::string &process_type); // sets process_type
  void setMemorySize(const int &memory_size);           // sets memory_size
  void setPID(const int &pid);                          // sets pid EXPLORE AUTO-INCREMENT
  std::string getProcessType() const;                   // @return process type
  long long int getMemorySize() const;                  // @return memory size
  int getPID() const;                                   // @return pid

}; //end Process

#endif // PROCESS_H