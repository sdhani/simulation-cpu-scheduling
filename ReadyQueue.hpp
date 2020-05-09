#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#include "Process.hpp"
#include <deque>

class ReadyQueue
{
private:
  Memory m_;
  long long int TOTAL_RAM_MEMORY_;
  long long int avail_memory_;             // total memory available for process creation and use
  int pid_count_ = 1;                      // keep track of PID
  int size_ = 0;                           // current size of Ready Queue
  std::deque<Process> ready_queue_rt_;     // rt level ready queue
  std::deque<Process> ready_queue_common_; // common level ready queue

public:
  ReadyQueue();
  ReadyQueue(const long long int &total_memory); // declare new ReadyQueue with x RAM

  bool addProcess(Process &new_process);           // add process to ReadyQueue, return success
  Process getProcessOnCPU();                       // @return process currently using the CPU
  bool terminateCurrentProcess();                  // @return successful, terminate current running process
  void endTimeSlice();                             // end time slice, give cpu to next process
  long long int getAvailMemory() const;            // @return amount of memory available
  int getSize() const;                             // @return current size of Ready Queue
  std::deque<Process> getRTReadyQueue() const;     // @return RT Ready Queue
  std::deque<Process> getCommonReadyQueue() const; // @return Common Ready Queue
  void printReadyQueue();                          // print ready queue snapshot
  /* 
    As long as there is an RT process, when a time slice ends, will the CPU only handle RT processes, until all RT processes terminate and only Common processes are left? Or will the CPU serve all RT processes and THEN Common processes and THEN again RT processes and repeat
  */

  // on common process, pop queue for preemptive rt
  // process on the "CPU" is the process at the "front of the RT queue, if not empty"
  // else first of common queue if not empty else no current process running, create
  // one
};

#endif // READY_QUEUE_H