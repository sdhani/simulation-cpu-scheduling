#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#include "Process.hpp"
#include <deque>

class ReadyQueue
{
private:
  long long int size_ = 0;                 // current size of Ready Queue
  std::deque<Process> ready_queue_rt_;     // rt level ready queue
  std::deque<Process> ready_queue_common_; // common level ready queue

public:
  ReadyQueue();
  bool addProcess(Process &new_process);           // add process to ReadyQueue, return success
  Process getProcessOnCPU() const;                 // @return process pid currently using the CPU
  bool terminateCurrentProcess();                  // @return successful, terminate current running process
  void endTimeSlice();                             // end time slice, give cpu to next process
  long long int getSize() const;                   // @return current size of Ready Queue
  std::deque<Process> getRTReadyQueue() const;     // @return RT Ready Queue
  std::deque<Process> getCommonReadyQueue() const; // @return Common Ready Queue
  void printReadyQueue();                          // print ready queue snapshot

  // on common process, pop queue for preemptive rt
  // process on the "CPU" is the process at the "front of the RT queue, if not empty"
  // else first of common queue if not empty else no current process running, create
  // one
};

#endif // READY_QUEUE_H