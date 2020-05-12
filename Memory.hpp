#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "MemBlock.hpp"
#include "Process.hpp"

class Memory
{
private:
  std::vector<MemBlock> continguous_memory_; /* Some data type that shows which processes using how much memory */
  long long int memory_size_;
  long long int free_memory_;

public:
  Memory(); // default constructor
  Memory(const long long int &memory_size);

  void setMemorySize(const long long int &memory_size); // sets size of RAM memory
  long long int getMemorySize() const;                  // @return size of RAM memory
  std::vector<MemBlock> getContiguousMemory() const;    // @return memory list
  void printMemory();                                   // print out memory snapshot with consolidated memory holes
  void consolidateMemoryChunks();                       // @group memory chunks next to each other
  bool addProcessToMemory(const Process &p);            // @return true if add process to memory is successful
  bool removeProcessFromMemory(const Process &p);       // @return true if remove process from memory is successful

}; //end Memory

#endif // MEMORY_H