#include "CPU.hpp"

// default constructor
CPU::CPU(){};

// parameterized constructor
CPU::CPU(const Process &currently_serving)
{
  currently_serving_ = currently_serving;
}

// @return true if CPU is idle
bool CPU::isIdle() const
{
  return is_idle_;
}

// @return process CPU is currently serving
Process CPU::currentlyServing() const
{
  return currently_serving_;
}

// set CPU status (boolean)
void CPU::setIsIdle(const bool &is_idle)
{
  is_idle_ = is_idle;
}

// set process CPU is currently serving
void CPU::setCurrentProcess(const Process &currently_serving)
{
  currently_serving_ = currently_serving;
}
