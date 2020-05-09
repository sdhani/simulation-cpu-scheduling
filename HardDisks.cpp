#include "HardDisks.hpp"

// default constructor
HardDisks::HardDisks() {}

// parameterized constructor
HardDisks::HardDisks(const int &total)
{
  total_ = total;
  for (int i = 0; i < total; i++)
  {
    IOQueue io_queue;
    hard_disks_.insert(std::make_pair(i, io_queue));
  }
}

// set total hard disks
void HardDisks::setTotal(const int &total)
{
  total_ = total;
}

// @return hard disks in use by process
std::unordered_map<int, IOQueue> HardDisks::getHardDiskUsage() const
{
  return hard_disks_;
}

// @return total hard disks
int HardDisks::getTotalDisks() const
{
  return total_;
}

// @return true if disk number is idle
bool HardDisks::isIdle(const int &disk_number) const
{
  /* Get I/O queue for  hard disk with disk_number */
  auto got = hard_disks_.find(disk_number);

  if (got == hard_disks_.end())
  {
    std::cout << "Disk # " << disk_number << "  does not exist" << std::endl;
  }
  else if (got->second.getIOQueue().empty())
  {
    return true;
  }

  return false;
}

// @return process using Hard Disk
Process HardDisks::usingHardDisk(const int &disk_number) const
{
  /* Get I/O queue for  hard disk with disk_number */
  auto got = hard_disks_.find(disk_number);

  if (got == hard_disks_.end())
  {
    std::cout << "Disk # " << disk_number << "  does not exist" << std::endl;
  }
  else if (got->second.onDisk().getPID() != -1)
  {
    std::cout << "Valid Process" << std::endl;
  }
  else
  {
    std::cout << "Invalid Process, PID: -1" << std::endl;
  }
  return got->second.onDisk();
}

// print hard disks snapshot
void HardDisks::printHardDisks()
{
  std::cout << "This has to be ordered prolly" << std::endl;

  for (auto &p : hard_disks_)
  {
    std::cout << "Hard Disk: " << p.first << std::endl;
    std::cout << "Serving: " << p.second.getIOQueue().front().getPID() << std::endl;
    // std::deque<Process> io_queue = p.second.getIOQueue();
    for (Process q : p.second.getIOQueue())
    {
      std::cout << q.getPID() << std::endl;
    }
  }
}
