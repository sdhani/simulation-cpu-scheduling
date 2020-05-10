#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "MemRange.hpp"

class Memory
{
private:
  struct MemBlock
  {
    int start_;
    int end_;
    int pid_;
    int memory_chunk_;
    bool active_;
  };
  std::vector<MemBlock> continguous_memory_; /* Some data type that shows which processes using how much memory */
  long long int memory_size_;
  long long int free_memory_;

public:
  Memory(); // default constructor
  Memory(const long long int &memory_size);

  void setMemorySize(const int &memory_size);        // sets size of RAM memory
  long long int getMemorySize() const;               // @return size of RAM memory
  bool addProcessToMemory(const Process &p);         // @return true if add process to memory is successful
  bool removeProcessFromMemory(const Process &p);    // @return true if remove process from memory is successful
  std::vector<MemBlock> getContiguousMemory() const; // @return memory list
  void printMemory() const;                          // print out memory snapshot

}; //end Memory

#endif // MEMORY_H