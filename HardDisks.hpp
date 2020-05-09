#ifndef HARD_DISKS_H
#define HARD_DISKS_H

#include <iostream>
#include <unordered_map>
#include "IOQueue.hpp"

class HardDisks
{
private:
  int total_ = 0;
  std::unordered_map<int, IOQueue> hard_disks_; // vector of pairs of process and ifOccupied

public:
  HardDisks();                                               // default constructor
  HardDisks(const int &total);                               // parameterized constructor
  void setTotal(const int &total);                           // set total hard disks
  std::unordered_map<int, IOQueue> getHardDiskUsage() const; // @return hard disks in use by process
  int getTotalDisks() const;                                 // @return total hard disks
  bool isIdle(const int &disk_number) const;                 // @return true if disk number is idle
  Process usingHardDisk(const int &disk_number) const;       // @return process using Hard Disk
  void printHardDisks();                                     // print hard disks snapshot

}; //end HardDisks

#endif // HARD_DISKS_H