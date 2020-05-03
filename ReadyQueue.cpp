#include "ReadyQueue.h"

/* Default Constructor */
ReadyQueue::ReadyQueue(){}

/* Parameterized Constructor */
ReadyQueue::ReadyQueue(const long long int& total_memory) {
  // declare new ReadyQueue with x RAM
  TOTAL_RAM_MEMORY_ = total_memory; // keep track of total memory capacity
  avail_memory_ = total_memory; // starting val for memory
} 

/* New process arrives/is created */
// @return success
bool ReadyQueue::addProcess(Process& new_process) {
  // add process to ReadyQueue, return success
  if(avail_memory_ >= new_process.getMemorySize()){
    if(new_process.getProcessType() == "RT") {   
      /* if RT-process arrives while common process is running, common process gets 
      preemptied and sent to the head of the common processes ready-queue. */
      // if(getProcessOnCPU().getProcessType() == "C"){} DOES THIS BY DEFAULT

      avail_memory_ -= new_process.getMemorySize();
      new_process.setPID(pid_count_);  
      ready_queue_rt_.push_back(new_process);
      pid_count_++; // update process id count
      size_++;

    } else { 
      avail_memory_ -= new_process.getMemorySize();
      new_process.setPID(pid_count_);  
      ready_queue_common_.push_back(new_process);
      pid_count_++; // update process id count
      size_++;

    }
    return true;
  } else {
    std::cout << "Not enough memory to add new process" << std::endl;
    return false;
  }
} 

// @return current process on the CPU
Process ReadyQueue::getProcessOnCPU() {
  // get process at top of deque
  if(!ready_queue_rt_.empty()){
    return ready_queue_rt_.front();
  } else {
    return ready_queue_common_.front();
  }
} 

/* Terminate current process */
// @return success
bool ReadyQueue::terminateCurrentProcess() {
  // pop process on top of deque

  if(!ready_queue_rt_.empty()){
    std::cout << "Terminated RT process #" << ready_queue_rt_.front().getPID() << std::endl;  
    avail_memory_ += ready_queue_rt_.front().getMemorySize();
    ready_queue_rt_.pop_front();
    size_--;

  } else if(!ready_queue_common_.empty()){
    std::cout << "Terminated Common process #" << ready_queue_common_.front().getPID() << std::endl;  
    avail_memory_+= ready_queue_common_.front().getMemorySize();
    ready_queue_common_.pop_front();
    size_--;

  } else {
    std::cout << "No process to terminate. " << std::endl;
    return false;
  }

  return true;
}

/* End Current Process's use of CPU; Round Robin logic */
void ReadyQueue::endTimeSlice() { 
  // end time slice, give cpu to next process
  if(!ready_queue_rt_.empty()){
    /* Send current process to end of queue */
    Process current_process = ready_queue_rt_.front();
    ready_queue_rt_.pop_front();
    ready_queue_rt_.push_back(current_process);

  } else if(!ready_queue_common_.empty()){
    /* Send current process to end of queue */
    Process current_process = ready_queue_common_.front();
    ready_queue_common_.pop_front();
    ready_queue_common_.push_back(current_process);
  }
}

// @return amount of memory available
long long int ReadyQueue::getAvailMemory() const {
  return avail_memory_;
} 

// @return current size of Ready Queue
int ReadyQueue::getSize() const {
  return size_;
} 

// @return RT Ready Queue
std::deque<Process> ReadyQueue::getRTReadyQueue() const {
  return ready_queue_rt_;
} 

// @return Common Ready Queue
std::deque<Process> ReadyQueue::getCommonReadyQueue() const {
  return ready_queue_common_;
} 