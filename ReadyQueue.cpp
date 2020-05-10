#include "ReadyQueue.hpp"
#include <iomanip>

/* Default Constructor */
ReadyQueue::ReadyQueue() {}

/* New process arrives/is created */
// @return success
bool ReadyQueue::addProcess(Process &new_process)
{
  if (new_process.getProcessType() == "RT")
  {
    ready_queue_rt_.push_back(new_process);
    size_++;
    return true;
  }
  else if (new_process.getProcessType() == "C")
  {
    ready_queue_common_.push_back(new_process);
    size_++;
    return true;
  }
  else
  {
    return false;
  }
}

// @return current process on the CPU
Process ReadyQueue::getProcessOnCPU() const
{
  // get process at top of deque
  if (!ready_queue_rt_.empty())
  {
    return ready_queue_rt_.front();
  }
  else
  {
    return ready_queue_common_.front();
  }
}

/* Terminate current process */
// @return success
bool ReadyQueue::terminateCurrentProcess()
{
  // pop process on top of deque

  if (!ready_queue_rt_.empty())
  {
    std::cout << "Terminated RT process #" << ready_queue_rt_.front().getPID() << std::endl;
    ready_queue_rt_.pop_front();
    size_--;
  }
  else if (!ready_queue_common_.empty())
  {
    std::cout << "Terminated Common process #" << ready_queue_common_.front().getPID() << std::endl;
    ready_queue_common_.pop_front();
    size_--;
  }
  else
  {
    std::cout << "No process to terminate. " << std::endl;
    return false;
  }
  return true;
}

/* End Current Process's use of CPU; Round Robin logic */
void ReadyQueue::endTimeSlice()
{
  // end time slice, give cpu to next process
  if (!ready_queue_rt_.empty())
  {
    /* Send current process to end of queue */
    Process current_process = ready_queue_rt_.front();
    ready_queue_rt_.pop_front();
    ready_queue_rt_.push_back(current_process);
  }
  else if (!ready_queue_common_.empty())
  {
    /* Send current process to end of queue */
    Process current_process = ready_queue_common_.front();
    ready_queue_common_.pop_front();
    ready_queue_common_.push_back(current_process);
  }
}

// @return current size of Ready Queue
int ReadyQueue::getSize() const
{
  return size_;
}

// @return RT Ready Queue
std::deque<Process> ReadyQueue::getRTReadyQueue() const
{
  return ready_queue_rt_;
}

// @return Common Ready Queue
std::deque<Process> ReadyQueue::getCommonReadyQueue() const
{
  return ready_queue_common_;
}

// print ready queue snapshot
void ReadyQueue::printReadyQueue()
{
  std::cout << "CPU: ";
  int cpu_pid = -1;

  // get process at top of deque
  if (!ready_queue_rt_.empty())
  {
    cpu_pid = ready_queue_rt_.front().getPID();
    std::cout << ready_queue_rt_.front().getPID() << std::endl;
  }
  else if (!ready_queue_common_.empty())
  {
    cpu_pid = ready_queue_common_.front().getPID();
    std::cout << ready_queue_common_.front().getPID() << std::endl;
  }
  else
  {
    std::cout << "IDLE" << std::endl;
  }

  //================================================================================================
  for (auto p : ready_queue_rt_)
  {
    if (p.getPID() != cpu_pid)
    {
      std::cout << p.getPID() << "| " << p.getProcessType() << "| " << p.getMemorySize() << std::endl;
    }
  }

  for (auto p : ready_queue_common_)
  {
    if (p.getPID() != cpu_pid)
    {
      std::cout << p.getPID() << "| " << p.getProcessType() << "| " << p.getMemorySize() << std::endl;
    }
  }
}
