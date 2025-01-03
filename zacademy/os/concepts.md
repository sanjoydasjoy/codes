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
<img src="chapters/pics/call_program.png" alt="Four Components of OS" width=400"> <br><br>

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

 <br><br>
## Process Scheduling <br>

Process Scheduling aims to maximize CPU usage by efficiently switching processes for time-sharing.  <br>
Schedulers: <br>

	• Short-term Scheduler (CPU Scheduler): Selects the next process for CPU execution, invoked frequently (milliseconds). 
	• Long-term Scheduler (Job Scheduler): Selects processes for the ready queue, invoked infrequently (seconds, minutes), controls multiprogramming degree.
	• Medium-term Scheduling: Removes processes from memory (swapping) when the degree of multiprogramming needs to decrease.


 <br><br>
## Context Switch <br>
	• When CPU switches to another process, the system must save the state of the old process
	• and load the saved state for the new process via a context switch
 
● Context of a process represented in the PCB <br>
● Context-switch time is overhead; the system does no useful work <br>
● While switching, the more complex the OS and the PCB  the longer the context switch <br>

 <br><br>
## Interprocess Communication
Interprocess Communication (IPC) is a mechanism that allows processes to communicate with each other within a system <br>
Types of Processes: <br>

	• Independent Processes: These processes do not interact with other processes.
	• Cooperating Processes: These processes can affect or be affected by other processes. They typically share data or perform tasks collaboratively.

Advantages of process cooperation / cooperating Processes / IPC:  <br>

	1. Information Sharing
	2. Computation Speedup
	3. Modularity: enhancing code reusability.
	4. Convenience: Cooperation between processes makes it easier to manage complex tasks.


● Cooperating processes need interprocess communication (IPC) <br>
● Two models of IPC ● Shared memory ● Message passing <br>

<img src="chapters/pics/ipc.png" alt="Four Components of OS" width="500"> 
<img src="chapters/pics/ipc2.png" alt="Four Components of OS" width="400"> 


<br> <br>

## Communications in Client-Server Systems
	● Sockets
	● Remote Procedure Calls
	● Pipes
	● Remote Method Invocation (Java)
<br><br>
 ● **Sockets (&ports)**  <br>
 
	● A socket is defined as an endpoint for communication
 	● Three types of sockets: 
  
  		1. Connection-oriented (TCP): Reliable, ordered, but slower. Used for web browsing or file downloads where accuracy is essential.
    			Like making a phone call—first (Voice Calls), you dial (establish a connection), then talk (send data), and when done, you hang up (close the connection). It's reliable but has more overhead. 
    
		2. Connectionless (UDP): Faster, less reliable, and unordered. Ideal for video streaming, online gaming, where slight data loss is acceptable for real-time performance. The video stream starts transmitting immediately, without waiting for a formal connection to be established. This makes the start time faster. 
  			Like when we watch a video On-Demand Streaming (youTube, netflix), that is pre-recorded and stored on a server, we can pause, fast forward the video. Or Live Streaming (twitch, facebook Live, sports events, live video call  (real-time voice communication (like in Skype, WhatsApp, or Zoom calls)): This is real-time transmission of video content, typically not stored permanently. The content is broadcast as it's being recorded. 

		3. MulticastSocket (class): Extends the DatagramSocket class to support multicast (sending data to multiple recipients simultaneously). Used for group communication where data is sent to a multicast group address. Example: Live video broadcasts, stock market updates.



	● Concatenation of IP address and port – to uniquely identify a specific service or application running on a device
	● The socket 161.25.19.8:1625 refers to port 1625 on host 161.25.19.8
 
 	● Possible port numbers 2^16 = 65,536. 
  	● Since a 16-bit number can represent values from 0 to 65535, there are 65536 possible port numbers.
  	● However, port 0 is reserved and not typically used for regular communication.
 	● This leaves 1 to 65535 as the range of usable port numbers.
  
	● 0–1023: Well-known ports (reserved for standard services like HTTP - 80, HTTPS - 443, SSH - 22).
	● 1024–49151: These ports are registered by organizations or developers for specific applications. (For example: 3306: MySQL, 5432: PostgreSQL, 8080: Alternative HTTP)
	● 49152–65535: Dynamic/Ephemeral ports (used temporarily by clients for outbound connections).
 		Temporary Use: When a client initiates a connection (e.g., opening a web page or sending an email), the OS assigns a port from this range to uniquely identify the connection.
		Short-Lived: These ports are released and reused once the connection ends.
		Automatic Assignment: The OS dynamically selects an available port from this range without user intervention.

  		Example: A client wants to connect to a web server on port 80 (HTTP).
			Server: Listens on port 80 (fixed).
			Client: OS assigns an ephemeral port, e.g., 49160, to handle the connection.



<br><br>
 ● **Remote Procedure Call (RPC)** <br>
 
 	● In operating systems allows programs to run functions on other computers as if they were on the same machine <br>

<br><br>
 ● **Pipes** <br>
 
	● Pipes act as conduits(channel) for inter-process communication (IPC).
	● Unidirectional or bidirectional communication.
	● For bidirectional: half-duplex (one direction at a time) or full-duplex (simultaneous both directions).

	● Ordinary pipes are limited to unidirectional parent-child communication
	● While Named pipes offer bidirectional, more flexible, and multi-process communication, no parent-child relationship needed.
<br><br><br><br>

## Thread / MultiThread / Multicore
A thread, often called a lightweight process, is the basic unit of CPU utilization <br>

**Multithreading:** Multithreading is the capability of an operating system to support multiple, concurrent paths of execution within a single process. <br>
Key Features of Multithreading: <br>

	1. Shared Resources: Threads within the same process share the same memory space and resources, such as files and data buffers, 
 			     making inter-thread communication more straightforward and faster than inter-process communication. <br>
 
	2. Context Switching: Switching between threads is typically faster than switching between processes. 
 			      Context switches among threads involve less overhead than between processes because threads share the same memory and resources. 

<br><br><br><br>
**Multicore**
A multicore system has a single processor with multiple execution units called cores, while a multiprocessor system has two or more processors. <br>

Key Concepts:<br>
1. Concurrency <br>
2. Parallelism <br>

**Difference between Concurrency and Parallelism** <br>

	Concurrency is the ability of a system to handle multiple tasks at the same time. 
 	These tasks might not actually run simultaneously; instead, they can be interleaved, 
  	meaning the system can switch between tasks quickly, giving the illusion of parallelism. 
	Concurrency can be done by using a single processing unit.


	Parallelism is the simultaneous execution of multiple tasks.
	While this can’t be done by using a single processing unit. it needs multiple processing units.


<br><br><br><br>

**Multithreading Models** <br>


	• Many-to-One Model: Multiple user-level threads are mapped to a single kernel-level thread. This approach is simple but can lead to poor performance if a user thread blocks, as it blocks the entire process.

	• One-to-One Model: Each user-level thread corresponds to a separate kernel-level thread. This model provides better concurrency as blocking one thread doesn't affect others, but it can be resource-intensive due to the overhead of managing multiple kernel-level threads.

	• Many-to-Many Model: Many user-level threads are multiplexed to a smaller or equal number of kernel-level threads, providing flexibility and a balance between concurrency and resource utilization.


<br><br><br><br>

**Implicit Threading**  <br>

Implicit threading refers to a technique where the creation and management of threads are handled automatically by compilers and runtime libraries rather than programmers. <br>


Three methods explored <br>

	● Thread Pools 
	● OpenMP 
	● Grand Central Dispatch

	1. A thread pool is a collection of pre-created threads that are ready to perform tasks. When a new task arrives, it is assigned to an available thread from the pool, which reduces the time and resources needed compared to creating a new thread each time.

	   Advantages:
	   Performance Efficiency:
	   Reduced Overhead: It is usually faster to service a request using an existing thread from the pool rather than creating a new
	   		     thread each time a task needs to be performed. This reduces the overhead associated with thread creation and destruction.



	2. OpenMP is a tool that helps programs run faster by doing several tasks at once. It works with languages like C, C++, and FORTRAN to make it easier for programmers to write code that can handle multiple tasks simultaneously on multi-core computers.




	3. Grand Central Dispatch (GCD) is a feature from Apple that helps apps run faster by managing tasks in the background.
			Grand Central Dispatch (GCD) in Apple's operating systems uses two main types of queues to manage how tasks (or blocks of code) are executed in an application:


