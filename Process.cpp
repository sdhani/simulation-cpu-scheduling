#include "Process.h"

//default constructor
Process::Process() {}

//@param process_type, Type of Process
//@param memory_size, Memory Size of Process 
//@param pid, PID of Process
//constructor, takes in Process info to create Process object
Process::Process(const std::string& process_type, const int& memory_size, const int& pid) {
  process_type_ = process_type; /* Common Process or RT-process */
  memory_size_ = memory_size;
  pid_ = pid; /* Don't reassign PID's */
}

// sets process_type
//@param process_type, Type of Process   
void Process::setProcessType(std::string process_type) {
  process_type_ = process_type;
} 

// sets memory_size
//@param memory_size, Memory Size of Process 
void Process::setMemorySize(int memory_size) {
  memory_size_ = memory_size;
} 

// sets pid EXPLORE AUTO-INCREMENT/COUNT OF PROCESSES "BAG"
void Process::setPID(int pid) {
  pid_ = pid;
} 

// @return process type
std::string Process::getProcessType() const {
  return process_type_;
} 

// @return memory size
int Process::getMemorySize() const {
  return memory_size_;
} 

// @return pid
int Process::getPID() const {
  return pid_;
} 
