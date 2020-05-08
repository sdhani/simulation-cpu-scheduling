#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <list>
#include <vector>
#include "MemRange.h"

class Memory
{
private:
  std::list<MemRange> continguous_memory_; /* Some data type that shows which processes using how much memory */
  long long int memory_size_ = 0;

public:
  Memory(); // default constructor
  Memory(const long long int &memory_size);

  void setMemorySize(const int &memory_size);      // sets size of RAM memory
  long long int getMemorySize() const;             // @return size of RAM memory
  std::list<MemRange> getContiguousMemory() const; // @return memory list
  void printMemory() const;                        // print out memory snapshot

}; //end Memory

#endif // MEMORY_H