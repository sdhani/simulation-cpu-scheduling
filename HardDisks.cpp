/**
 * Author: Shania Dhani
 * Date Modified May 12, 2020
 * 
 * Hard Disks keeps track of all devices in the simulation and the 
 * processes that are using the hard disks and the processes waiting 
 * to use the hard disk.
 */

#include <iostream>
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
    hard_disks_.push_back(io_queue);
  }
}

// set total hard disks
void HardDisks::setTotal(const int &total)
{
  total_ = total;
}

// @return hard disks in use by process
std::vector<IOQueue> HardDisks::getHardDiskUsage() const
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
  if (unsigned(disk_number) < hard_disks_.size())
  {
    if (hard_disks_[disk_number].onDisk().getPID() == -1)
    {
      return true;
    }
  }
  return false;
}

// serve process on hard disk number
bool HardDisks::requestDisk(const int &disk_number, const Process &cpu_process)
{
  if (unsigned(disk_number) < hard_disks_.size())
  {
    hard_disks_[disk_number].addProcess(cpu_process);
    return true;
  }
  return false;
}

// end process at disk_number use
bool HardDisks::endDiskUse(const int &disk_number, Process &finished_process)
{
  if (unsigned(disk_number) < hard_disks_.size())
  {
    finished_process = hard_disks_[disk_number].onDisk();
    hard_disks_[disk_number].endProcess(); /* end process on hard disk */
    return true;
  }
  return false;
}

// @return process using Hard Disk
Process HardDisks::usingHardDisk(const int &disk_number) const
{
  return hard_disks_[disk_number].onDisk(); /* returns pid -1 */
}

// print hard disks snapshot
void HardDisks::printHardDisks()
{
  for (unsigned i = 0; i < hard_disks_.size(); i++)
  {
    IOQueue &p = hard_disks_[i];
    std::cout << "   HDD ";
    std::cout << std::to_string(i) << ": ";
    std::cout << ((p.onDisk().getPID() == -1) ? "IDLE" : "P" + std::to_string(p.onDisk().getPID()));

    std::cout << "  | I/O Queue: ";
    if (!p.isEmpty())
    {
      for (unsigned i = 0; i < p.getIOQueue().size(); i++)
      {
        Process q = p.getIOQueue()[i];
        if (i != 0 && q.getPID() != -1)
        {
          std::cout << "P" << q.getPID() << ", ";
        }
      }
    }
    std::cout << std::endl;
  }
}
