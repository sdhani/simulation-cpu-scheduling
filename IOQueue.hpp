#ifndef IO_QUEUE_H
#define IO_QUEUE_H

#include <queue>
#include "Process.hpp"

class IOQueue
{
private:
  /*!! Important Note: Process at position 0 is using the Hard Disk !!*/
  std::deque<Process> io_queue_; // processes waiting to use th IO queue.

public:
  IOQueue();                              // default constructor
  void addProcess(const Process &p);      // add process to i/o queue for this device
  void endProcess();                      // terminate process currently using the disk; pop queue
  bool isEmpty() const;                   // @return true if only one process on "queue"
  Process onDisk() const;                 // @return process using the hard disk; queue.front()
  std::deque<Process> getIOQueue() const; // @return io queue
};                                        //end IOQueue

#endif // IO_QUEUE_H