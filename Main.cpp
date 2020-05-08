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

using namespace std;

// main
int main()
{
  long long int TOTAL_RAM_MEMORY = 0;
  long long int TOTAL_HARD_DISKS = 0;

  cout << "How much RAM memory is there on the simulated computer?" << endl;
  cin >> TOTAL_RAM_MEMORY;

  cout << "Your program receives the number in bytes (no kilobytes or words)." << endl;
  cin >> TOTAL_HARD_DISKS;

  cout << "TOTAL_RAM_MEMORY: " << TOTAL_RAM_MEMORY << ", "
       << "TOTAL_HARD_DISKS: " << TOTAL_HARD_DISKS << endl;

  while (true)
  {
    char command = ' ';
    cin >> command;

    cout << ": " << command << endl;
    if (command == 'S')
    {
      char second_command = ' ';
      cin >> second_command;
      if (second_command == 'r')
      {
        cout << "Shows what process is currently using the CPU and what processes are waiting on both levels of the ready-queue." << endl;
      }
      else if (second_command == 'i')
      {
        cout << "Shows what processes are currently using the hard disks and what processes are waiting to use them. For each busy hard disk show the process that uses it and show its I/O-queue. The enumeration of hard disks starts from 0." << endl;
      }
      else if (second_command == 'm')
      {
        cout << "Shows the state of memory. Show the range of memory addresses used by each process in the system." << endl;
      }
      else
      {
        cout << "No specific view requested." << endl;
      }
    }

    /* Should I count A 100  0 00 as A 100000? */
    if (command == 'A')
    {
      long memory_size = 0;
      cin >> memory_size;

      cout << "Memory Size: " << memory_size << endl;
    }
  }

  return 0;
}