#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

class Process
{
private: 
    std::string process_type_; /* Common Process or RT-process */
    int memory_size_ = 0;
    int pid_ = 0; /* Don't reassign PID's */

public: 
    Process(); // default constructor
    Process(const std::string& process_type_, const std::string& memory_size_, const int& pid_);
   
    
    void setProcessType(std::string process_type); // sets process_type
    void setMemorySize(int memory_size); // sets memory_size
    void setPID(int pid); // sets pid EXPLORE AUTO-INCREMENT/COUNT OF PROCESSES "BAG"
    std::string getProcessType() const; // @return process type
    std::string getMemorySize() const; // @return memory size
    std::string getPID() const; // @return pid

}; //end Process

#endif  // PROCESS_H