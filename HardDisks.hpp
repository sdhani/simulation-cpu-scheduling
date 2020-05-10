#ifndef HARD_DISKS_H
#define HARD_DISKS_H

#include <iostream>
#include <unordered_map>
#include "IOQueue.hpp"

class HardDisks
{
private:
  int total_ = 0;
  std::vector<IOQueue> hard_disks_;

public:
  HardDisks();                                                          // default constructor
  HardDisks(const int &total);                                          // parameterized constructor
  void setTotal(const int &total);                                      // set total hard disks
  std::vector<IOQueue> getHardDiskUsage() const;                        // @return hard disks in use by process
  int getTotalDisks() const;                                            // @return total hard disks
  bool isIdle(const int &disk_number) const;                            // @return true if disk number is idle
  bool requestDisk(const int &disk_number, const Process &cpu_process); // serve process on hard disk number
  bool endDiskUse(const int &disk_number, Process &finished_process);   // end process at disk_number use
  Process usingHardDisk(const int &disk_number) const;                  // @return process using Hard Disk

  void printHardDisks(); // print hard disks snapshot

}; //end HardDisks

#endif // HARD_DISKS_H