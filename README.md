## CPU Scheduling Simulation 👾

### CPU scheduling scheme:
- 2 levels of a **Ready-Queue**: one for Real-Time processes and one for Common processes.
- Each level practices round-robin.
- Real-Time processes have **priority**. Run Common processes only if there are no Real-Time processes waiting to use the CPU. If a Real-Time process arrives while a Common process is running, the Common process will be  **preempted** and sent to the *head* of the Common processes' Ready-Queue.
 

- I/O-queues are **First Come First Serve** (FCFS).
- **Memory**: **Contiguous Memory Management** with **“first-fit”** approach.

```bash
# start of the simulation prompt
How much RAM memory is there on the simulated computer? (Up to 4 billions).
How many hard disks does the simulated computer have? 

# After this, the simulation begins. The program is constantly listening for user inputs. Possible inputs are:
 ```

### Acceptable Commands

- `A`   size     ‘A’ input means that a new common process has been created. When the new process arrives, your program should create its PCB and place the process in the ready-queue or the CPU. The requested amount of memory should be allocated for the new process. When choosing a PID for the new process start from 1 and go up. Do NOT reuse PIDs of the terminated processes. For example, the command A 1000 means that a new common process has been created and it requires 1000 bytes of memory.

- `AR`  size   the same as ‘A’ but the new process is an RT-process. 

- `Q`   means that the time slice has ended for the currently running process.

- `t`   currently running process terminates 

- `d number`       The process that currently uses the CPU requests the hard disk #number.

- `D number`   The hard disk #number has finished the work for one process.

- `S r`     Shows what process is currently using the CPU and what processes are waiting on both levels of the ready-queue.

- `S i`      Shows what processes are currently using the hard disks and what processes are waiting to use them. For each busy hard disk show the process that uses it and show its I/O-queue. The enumeration of hard disks starts from 0.

- `S m`   Shows the state of memory. Show the range of memory addresses used by each process in the system.

## Run Locally:

1. Clone repo.
1. Navigate to the root directory of the project.
1. Run `make all` to compile the program.
1. Run `./Simulation` to start the program.
1. Follow the simulation's instructions to interact with the program! :tada:

> April 2020
