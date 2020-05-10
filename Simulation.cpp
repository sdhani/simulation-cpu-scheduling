#include <sstream>
#include "Simulation.hpp"

Simulation::Simulation() {} // default constructor

Simulation::Simulation(const Memory &ram_memory, const HardDisks &hard_disks)
{
  RAM_MEMORY_ = ram_memory;
  HARD_DISKS_ = hard_disks;
}

// sets size of RAM Simulation
void Simulation::setRAM(const Memory &ram_memory)
{
  RAM_MEMORY_ = ram_memory;
}

// set CPU
void Simulation::setCPU(const CPU &cpu)
{
  CPU_ = cpu;
}

// sets ready_queue
void Simulation::setReadyQueue(const ReadyQueue &ready_queue)
{
  READY_QUEUE_ = ready_queue;
}

// sets hard disks
void Simulation::setHardDisks(const HardDisks &hard_disks)
{
  HARD_DISKS_ = hard_disks;
}

// @return Memory
Memory Simulation::getMemory() const
{
  return RAM_MEMORY_;
}

// @return CPU
CPU Simulation::getCPU() const
{
  return CPU_;
}

// @return Ready Queue
ReadyQueue Simulation::getReadyQueue() const
{
  return READY_QUEUE_;
}

// @return Hard Disks
HardDisks Simulation::getHardDisks() const
{
  return HARD_DISKS_;
}

//=======================================================================
// parses command line instructions
void parseCommand(const std::string &line, std::string &command, std::string &number)
{
  bool commandFinished = false;
  for (char c : line)
  {
    if (isalpha(c) && !commandFinished) /* Add more spohisticated check for aceepted characters */
    {
      command += c;
    }

    if (isdigit(c)) /* is digit c >= 48 && c <= 57 */
    {
      commandFinished = true;
      number += c;
    }
  }
}

// interpret command
void Simulation::interpretCommand(const std::string &line)
{
  std::string build_command = "", build_number = ""; /* Only applicable to A AR d & D Commands */
  long long int number = 0;

  parseCommand(line, build_command, build_number);
  std::stringstream convert_string(build_number); /* Convert string to number */
  convert_string >> number;

  if (!build_command.empty() && !build_number.empty())
  {
    if (build_command == "A")
    {
      executeACommand(number);
    }
    else if (build_command == "AR")
    {
      executeARCommand(number);
    }
    else if (build_command == "d")
    {
      executedCommand(number);
    }
    else if (build_command == "D")
    {
      executeDCommand(number);
    }
    else
    {
      std::cout << "Invalid command, expected a number. Note Commands are case-sensitive" << std::endl;
    }
  }
  else if (!build_command.empty() && build_number.empty())
  {
    if (build_command == "Q")
    {
      executeQCommand();
    }
    else if (build_command == "t")
    {
      executeTCommand();
    }
    else if (build_command == "Sr")
    {
      printSR();
    }
    else if (build_command == "Si")
    {
      printSI();
    }
    else if (build_command == "Sm")
    {
      printSM();
    }
    else
    {
      std::cout << "Invalid Command. Note Commands are case-sensitive" << std::endl;
    }
  }
  else
  {
    std::cout << "Invalid Command. Note Commands are case-sensitive" << std::endl;
  }
}

// executes A # command, create common process
void Simulation::executeACommand(const long long int &process_memory_size)
{
  Process new_common_process("C", process_memory_size, PID_COUNT_);

  if (RAM_MEMORY_.addProcessToMemory(new_common_process))
  {
    READY_QUEUE_.addProcess(new_common_process);
    PID_COUNT_++; /* Increment Simulation Process Count */
  }
}

// executes AR # command, create real-time process
void Simulation::executeARCommand(const long long int &process_memory_size)
{
  Process new_rt_process("RT", process_memory_size, PID_COUNT_);
  if (RAM_MEMORY_.addProcessToMemory(new_rt_process))
  {
    READY_QUEUE_.addProcess(new_rt_process);
    PID_COUNT_++; /* Increment Simulation Process Count */
  }
}

// executes Q command; ends Round-Robin Time Slice
void Simulation::executeQCommand()
{
  READY_QUEUE_.endTimeSlice();
}

// executes t command; terminate currently running process
void Simulation::executeTCommand()
{
  /* terminate process on CPU */
  RAM_MEMORY_.removeProcessFromMemory(READY_QUEUE_.getProcessOnCPU());
  READY_QUEUE_.terminateCurrentProcess();
}

// executes d # command; process that currently uses the CPU requests the hard disk #
void Simulation::executedCommand(const int &disk_number)
{
  std::cout << "d Command Recieved, " << disk_number << std::endl;
}

// executes D # command; process on hard disk # has finished work; assign next process that wants hard disk # to hard disk
void Simulation::executeDCommand(const int &disk_number)
{
  std::cout << "D Command Recieved, " << disk_number << std::endl;
}

// get memory snapshot
void Simulation::printSM()
{
  // std::cout << "Shows the state of memory. Show the range of memory addresses used by each process in the system." << std::endl;
  RAM_MEMORY_.printMemory();
}

// get hard-disk and i/o snapshot
void Simulation::printSI()
{
  // std::cout << "Shows what processes are currently using the hard disks and what processes are waiting to use them. For each busy hard disk show the process that uses it and show its I/O-queue. The enumeration of hard disks starts from 0." << std::endl;
  HARD_DISKS_.printHardDisks();
}

// get ready-queue and cpu snapshot
void Simulation::printSR()
{
  // std::cout << "Shows what process is currently using the CPU and what processes are waiting on both levels of the ready-queue." << std::endl;
  READY_QUEUE_.printReadyQueue();
}
