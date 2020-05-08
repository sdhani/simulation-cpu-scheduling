#include "Simulation.h"

Simulation::Simulation() {} // default constructor

Simulation::Simulation(const Memory &ram_memory, /* const CPU &cpu, */ const ReadyQueue &ready_queue /*, const IOQueue &io_queue, const HardDisks &hard_disks */)
{
  RAM_MEMORY_ = ram_memory;
  // CPU_ = cpu;
  READY_QUEUE_ = ready_queue;
  // IO_QUEUE_ = io_queue;
  // HARD_DISKS_ = hard_disks;
}

// sets size of RAM Simulation
void Simulation::setRAM(const Memory &ram_memory)
{
  RAM_MEMORY_ = ram_memory;
}

// set CPU
// void Simulation::setCPU(const CPU &cpu){}

// sets ready_queue
void Simulation::setReadyQueue(const ReadyQueue &ready_queue)
{
  READY_QUEUE_ = ready_queue;
}

// sets ready_queue
// void Simulation::setIOQueue(const IOQueue &io_queue){}

// sets ready_queue
// void Simulation::setHardDisks(const HardDisks &hard_disks){}

// @return Memory
Memory Simulation::getMemory() const
{
  return RAM_MEMORY_;
}

// @return CPU
// CPU Simulation::getCPU() const {}

// @return Ready Queue
ReadyQueue Simulation::getReadyQueue() const
{
}

// @return I/O Queue
// IOQueue Simulation::getIOQueue() const {}

// @return Hard Disks
// HardDisks Simulation::getHardDisks() const {}

// get memory snapshot
void Simulation::printSM()
{
  // (Shows the state of memory. Show the range of memory addresses used by each process in the system.)
}

// get hard-disk and i/o snapshot
void Simulation::printSI()
{
  // (Shows what processes are currently using the hard disks and what processes are waiting to use them. For each busy hard disk show the process that uses it and show its I/O-queue. The enumeration of hard disks starts from 0.)
}

// get ready-queue and cpu snapshot
void Simulation::printSR()
{
  // (Shows what process is currently using the CPU and what processes are waiting on both levels of the ready-queue.)
}
