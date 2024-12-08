## What is an Operating System? <br>
● A program that acts as an intermediary between a user of a computer and the computer hardware <br><br>
<img src="chapters/pics/four_components_os.png" alt="Four Components of OS" width="350"> <br><br>

## Operating System vs Kernel <br>
<img src="chapters/pics/kernel_vs_os.png" alt="Four Components of OS" width="600"> <br><br>

For example, kernel as the engine of a car and the OS as the entire car, including the engine, body, seats, and controls. <br>
When we turn on the video player to play a movie, <br> 
the OS helps you open the video player, find the movie file, and run the app. The kernel makes sure the video player can use hardware like the GPU and speakers, and manages system resources (like memory and CPU) for everything to work smoothly. The OS is for user tasks, and the kernel handles the hardware. <br><br>

## System call vs System program <br> 
<img src="chapters/pics/system_call_system_program.png" alt="Four Components of OS" width="600"> 
<img src="chapters/pics/call_program.png" alt="Four Components of OS" width=350"> <br><br>

## Process <br> 
● Process -  a program in execution <br>
● Program is passive entity stored on disk (executable file), process is active <br>
● Program becomes process when executable file loaded into memory <br><br>
● Process State <br>
    ● new ● running ● waiting ● ready ● terminated <br><br>
<img src="chapters/pics/process_state.png" alt="Four Components of OS" width="500"> <br> <br>


## Process Control Block (PCB) <br>
A Process Control Block (PCB) also known as a Task Control Block, contains information about each process: <br>

	• Process State: Current status (running, waiting, etc.) 
	• Program Counter: Address of the next instruction to execute 
	• CPU Registers: Contents of process-specific registers 
	• Scheduling Info: Priority, queue pointers 
	• Memory Info: Allocated memory 
	• Accounting Info: CPU time used, time limits 
    • I/O Status: Devices and open files allocated to the process

## Process Scheduling <br>

Process Scheduling aims to maximize CPU usage by efficiently switching processes for time-sharing.  <br>
Schedulers: <br>

	• Short-term Scheduler (CPU Scheduler): Selects the next process for CPU execution, invoked frequently (milliseconds). 
	• Long-term Scheduler (Job Scheduler): Selects processes for the ready queue, invoked infrequently (seconds, minutes), controls multiprogramming degree.
	• Medium-term Scheduling: Removes processes from memory (swapping) when the degree of multiprogramming needs to decrease.















