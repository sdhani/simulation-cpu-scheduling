/**
 * Author: Shania Dhani
 * Date Modified May 12, 2020
 * 
 * Process represents a basic process in the simulation and contains a PID,
 * the process's memory size, and the process type (Real Time or Common, in this case).
 */

#include "Process.hpp"

//default constructor
Process::Process() {}

Process::Process(const Process &p)
{
  process_type_ = p.getProcessType();
  memory_size_ = p.getMemorySize();
  pid_ = p.getPID();
}

//@param process_type, Type of Process
//@param memory_size, Memory Size of Process
//@param pid, PID of Process
//constructor, takes in Process info to create Process object
Process::Process(const std::string &process_type, const long long int &memory_size, const long long int &pid)
{
  process_type_ = process_type; /* Common Process or RT-process */
  memory_size_ = memory_size;
  pid_ = pid; /* Don't reassign PID's */
}

// sets process_type
//@param process_type, Type of Process
void Process::setProcessType(const std::string &process_type)
{
  process_type_ = process_type;
}

// sets memory_size
//@param memory_size, Memory Size of Process
void Process::setMemorySize(const long long int &memory_size)
{
  memory_size_ = memory_size;
}

// sets pid EXPLORE AUTO-INCREMENT/COUNT OF PROCESSES "BAG"
void Process::setPID(const long long int &pid)
{
  pid_ = pid;
}

// @return process type
std::string Process::getProcessType() const
{
  return process_type_;
}

// @return memory size
long long int Process::getMemorySize() const
{
  return memory_size_;
}

// @return pid
long long int Process::getPID() const
{
  return pid_;
}
