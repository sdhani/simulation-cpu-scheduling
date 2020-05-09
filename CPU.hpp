#ifndef CPU_H
#define CPU_H

#include "Process.hpp"

class CPU
{
private:
  bool is_idle_ = true;
  Process currently_serving_;

public:
  CPU();                                                    // default constructor
  CPU(const Process &currently_serving);                    // parameterized constructor
  bool isIdle() const;                                      // @return true if CPU is idle
  Process currentlyServing() const;                         // @return process CPU is currently serving
  void setIsIdle(const bool &is_idle);                      // set CPU status (boolean)
  void setCurrentProcess(const Process &currently_serving); // set process CPU is currently serving

}; //end Simulation

#endif // CPU_H