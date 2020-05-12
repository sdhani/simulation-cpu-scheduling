/**
 * Author: Shania Dhani
 * Date Modified May 12, 2020
 * 
 * Simulates a single IO queue connected to a Hard Disk. Processes
 * waiting to use a particular Hard Disk is on this queue. The first 
 * element on the queue is currently "using" the Hard Disk.
 */

#include "IOQueue.hpp"

// default constructor
IOQueue::IOQueue() {}

// add process to i/o queue for this device
void IOQueue::addProcess(const Process &p)
{
  io_queue_.push_back(p);
}

// terminate process currently using the disk; pop queue
void IOQueue::endProcess()
{
  io_queue_.pop_front();
}

// @return process using the hard disk; queue.front()
Process IOQueue::onDisk() const
{
  if (io_queue_.empty())
  {
    Process p;
    p.setPID(-1);
    return p; // process does not exist
  }
  return io_queue_.front();
}

// @return true if 1 or less processes are on the "queue"
bool IOQueue::isEmpty() const
{
  return (io_queue_.size() <= 1);
}

// @return i/o queue (including process on disk at pos 0)
std::deque<Process> IOQueue::getIOQueue() const
{
  return io_queue_;
}
