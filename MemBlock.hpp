#ifndef MEMBLOCK_H
#define MEMBLOCK_H

class MemBlock
{
private:
  long long int start_;
  long long int end_;
  long long int pid_;
  long long int memory_chunk_;
  bool active_;

public:
  MemBlock(); // default constructor
  MemBlock(const long long int &start, const long long int &end, const long long int &pid,
           const long long int &memory_chunk, const bool active); // parameterized constructor

  void setStart(const long long int &start);              // set start range
  void setEnd(const long long int &end);                  // set end range
  void setMemoryChunk(const long long int &memory_chunk); // set memory_chunk size
  void setPID(const long long int &pid);                  // set pid
  void setActive(const bool &is_active);                  // set active
  long long int start() const;                            // @return start range
  long long int end() const;                              // @return end range
  long long int pid() const;                              // @return pid
  long long int memoryChunk() const;                      // @return memory chunk
  bool active() const;                                    // @return activity of process in memory
};

#endif // MEMBLOCK_H