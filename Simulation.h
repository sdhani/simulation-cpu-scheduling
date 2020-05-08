#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "Memory.h"
#include "CPU.h"
#include "ReadyQueue.h"
#include "IOQueue.h"
#include "HardDisks.h"

class Simulation
{
private:
  Memory RAM_MEMORY_;
  // CPU CPU_;
  ReadyQueue READY_QUEUE_;
  // IOQueue IO_QUEUE_;
  // HardDisks HARD_DISKS_;

public:
  Simulation();                       // default constructor
  Simulation(const Memory &ram_memory /*, const CPU &cpu,  const ReadyQueue &ready_queue , 
  const IOQueue &io_queue, const HardDisks &hard_disks */
  );

  void setRAM(const Memory &ram_memory); // sets size of RAM Simulation
  // void setCPU(const CPU &cpu); // set cpu
  void setReadyQueue(const ReadyQueue &ready_queue); // sets ready_queue
  // void setIOQueue(const IOQueue &io_queue); // sets ready_queue
  // void setHardDisks(const HardDisks &hard_disks); // sets ready_queue
  Memory getMemory() const; // @return Memory
  // CPU getCPU() const; // @return CPU
  ReadyQueue getReadyQueue() const; // @return Ready Queue
  // IOQueue getIOQueue() const; // @return I/O Queue
  // HardDisks getHardDisks() const; // @return Hard Disks

  void interpretCommand(std::string line);               // parses command line instructions
  void executeACommand(const int &process_memory_size);  // executes A # command, create common process
  void executeARCommand(const int &process_memory_size); // executes AR # command, create real-time process
  void executeQCommand();                                // executes Q command; ends Round-Robin Time Slice
  void executeTCommand();                                // executes t command; terminate currently running process
  void executedCommand();                                // executes d # command; process that currently uses the CPU requests the hard disk #
  void executeDCommand();                                // executes D # command; process on hard disk # has finished work; assign next process that wants hard disk # to hard disk

  void printSM(); // get memory snapshot (Shows the state of memory. Show the range of memory addresses used by each process in the system.)
  void printSI(); // get hard-disk and i/o snapshot (Shows what processes are currently using the hard disks and what processes are waiting to use them. For each busy hard disk show the process that uses it and show its I/O-queue. The enumeration of hard disks starts from 0.)
  void printSR(); // get ready-queue and cpu snapshot (Shows what process is currently using the CPU and what processes are waiting on both levels of the ready-queue.)

}; //end Simulation

#endif // SIMULATION_H