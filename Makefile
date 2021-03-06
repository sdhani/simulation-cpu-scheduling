# ##############################################
# ##
# ## Makefile
# ## LINUX compilation 
# ##
# ##############################################


# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

all: Main.o Simulation.o Memory.o ReadyQueue.o MemBlock.o Process.o HardDisks.o IOQueue.o CPU.o
	$(CXX) $(CXXFLAGS) -o Simulation Main.o Simulation.o Memory.o ReadyQueue.o MemBlock.o Process.o HardDisks.o IOQueue.o CPU.o

# The main.o target can be written more simply

Main.o: Main.cpp Simulation.hpp Memory.hpp ReadyQueue.hpp MemBlock.hpp Process.hpp HardDisks.hpp IOQueue.hpp CPU.o
	$(CXX) $(CXXFLAGS) -c Main.cpp

Simulation.o: Simulation.hpp

ReadyQueue.o: ReadyQueue.hpp Process.hpp

Memory.o: Memory.hpp MemBlock.hpp HardDisks.hpp IOQueue.hpp

MemBlock.o: MemBlock.hpp Process.hpp

Process.o: Process.hpp

HardDisks.o: HardDisks.hpp IOQueue.hpp

IOQueue.o: IOQueue.hpp

CPU.o: CPU.hpp


#Clean obj files
clean:
	(rm -f *.o; rm -f Simulation)