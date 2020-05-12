/**
 * Author: Shania Dhani
 * Date Modified May 12, 2020
 * 
 * The Ready Queue in this simulation has two levels, A Real Time process level
 * and a Common process level. Real Time processes can preempt Common processes
 * from using the CPU. Both levels of the Ready Queue practice Round-Robin CPU
 * Scheduling, and therefore responds to the 'Q' command as an end of time slice/quantum
 * action. 
 */

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
  else if (!ready_queue_common_.empty())
  {
    return ready_queue_common_.front();
  }
  else
  {
    Process err;
    err.setPID(-1);
    return err;
  }
}

/* Terminate current process */
// @return success
bool ReadyQueue::terminateCurrentProcess()
{
  // pop process on top of deque

  if (!ready_queue_rt_.empty())
  {
    ready_queue_rt_.pop_front();
    size_--;
  }
  else if (!ready_queue_common_.empty())
  {
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
long long int ReadyQueue::getSize() const
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

// helper print PID function
std::string printPID(const long long int &pid)
{
  return "P" + std::to_string(pid) + " ";
}

// print ready queue snapshot
void ReadyQueue::printReadyQueue()
{
  long long int cpu_pid = getProcessOnCPU().getPID();

  std::cout << "   CPU "
            << "| "
            << (cpu_pid == -1 ? "IDLE" : printPID(cpu_pid)) << std::endl;

  std::cout << "   RT-queue: ";
  for (auto p : ready_queue_rt_)
  {
    if (p.getPID() != cpu_pid)
    {
      std::cout << "<- " << printPID(p.getPID());
    }
  }

  std::cout << std::endl;
  std::cout << "   C-queue:  ";
  for (auto p : ready_queue_common_)
  {
    if (p.getPID() != cpu_pid)
    {
      std::cout << "<- " << printPID(p.getPID());
    }
  }
  std::cout << std::endl;
}
