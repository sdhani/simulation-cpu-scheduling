/**
 * Author: Shania Dhani
 * 
 * Description: This program simulates a CPU scheduling scheme with the following characteristics:
 *  -> There are two levels of a ready-queue: one for RT-processes and one for common processes.
 *  -> Round-Robin is practiced on each level.
 *  -> You run common processes only if there is no RT-processes waiting.
 *  -> If RT-process arrives while common process is running, common process gets preemptied and sent 
 *     to the head of the common processes ready-queue.
*/

#include <iostream>
#include "Simulation.hpp"

// main
int main()
{
  long long int TOTAL_RAM_MEMORY = 0;
  long long int TOTAL_HARD_DISKS = 0;

  std::cout << "How much RAM memory is there on the simulated computer?" << std::endl;
  std::cin >> TOTAL_RAM_MEMORY;

  std::cout << "Your program receives the number in bytes (no kilobytes or words)." << std::endl;
  std::cin >> TOTAL_HARD_DISKS;

  std::cout << "RAM: " << TOTAL_RAM_MEMORY << "| "
            << "HDD: " << TOTAL_HARD_DISKS << std::endl;

  Memory RAM(TOTAL_RAM_MEMORY);
  HardDisks HARD_DISKS(TOTAL_HARD_DISKS);
  Simulation cpu_scheduling(RAM, HARD_DISKS);

  std::string command;
  getline(std::cin, command);

  while (getline(std::cin, command))
  {
    cpu_scheduling.interpretCommand(command);
  }

  return 0;
}