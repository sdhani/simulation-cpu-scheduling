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
#include "Simulation.h"

// main
int main()
{
  long long int TOTAL_RAM_MEMORY = 0;
  long long int TOTAL_HARD_DISKS = 0;

  std::cout << "How much RAM memory is there on the simulated computer?" << std::endl;
  std::cin >> TOTAL_RAM_MEMORY;

  std::cout << "Your program receives the number in bytes (no kilobytes or words)." << std::endl;
  std::cin >> TOTAL_HARD_DISKS;

  std::cout << "TOTAL_RAM_MEMORY: " << TOTAL_RAM_MEMORY << ", "
            << "TOTAL_HARD_DISKS: " << TOTAL_HARD_DISKS << std::endl;

  Memory RAM(TOTAL_RAM_MEMORY);
  // CPU CPU(); can be defaulted in declared to idle
  // HardDisks HARD_DISKS (TOTAL_HARD_DISKS);
  // ReadyQueue RQ();
  Simulation cpu_scheduling(RAM /* ,cpu, RQ, ioqueue, harddisks*/);

  while (true)
  {
    char command = ' ';
    std::cin >> command;

    // std::cout << ": " << command << std::endl;
    if (command == 'S')
    {
      char second_command = ' ';
      std::cin >> second_command;
      if (second_command == 'r')
      {
        cpu_scheduling.printSR();
      }
      else if (second_command == 'i')
      {
        cpu_scheduling.printSI();
      }
      else if (second_command == 'm')
      {
        cpu_scheduling.printSM();
      }
      else
      {
        std::cout << "No specific view requested." << std::endl;
      }
    }

    /* Should I count A 100 */
    if (command == 'A')
    {
      char second_command = ' ';
      std::cin >> second_command;
      if (second_command == 'R')
      {
        cpu_scheduling.printSR();
      }
      long memory_size = 0;
      std::cin >> memory_size;

      std::cout << "Memory Size: " << memory_size << std::endl;
    }
  }

  return 0;
}