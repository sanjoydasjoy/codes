**chapter 5**

## CPU Scheduling

The dispatcher is a component of the operating system that switches control from the OS to a user process. <br>


The key functions of the dispatcher include: <br>

    1.Context Switching: Saving the state of the currently running process and loading the state of the next scheduled process.

    2.Switching to User Mode: Changing the mode of operation from kernel mode (where the OS executes) to user mode (where the user process runs).

    3.Jumping to the Correct Location: Ensuring the process resumes from the correct point within its program.

**Dispatch Latency** is the time it takes for the dispatcher to switch from one process to another. This includes the time for all the above steps and represents the overhead involved in process switching. <br>


<br><br>

**Scheduling Algorithm Optimization Criteria** 

        ● Max CPU utilization
        ● Max throughput
        ● Min turnaround time
        ● Min waiting time
        ● Min response time

<br><br>

## FCFS

FCFS stands for "First-Come, First-Served." It's a simple scheduling algorithm. <br>


FCFS schedules tasks in the order that they arrive or request service. <br>
The first task to arrive is the first to be served, and so forth, much like customers lining up at a checkout. <br>
Each task waits until the one in front of it gets completed. <br>

Key Features:

    	1. Non-preemptive: Once a process starts running, it continues until it finishes. There are no interruptions.
    	2. Simple to Implement: FCFS is straightforward because it requires minimal tracking—just the order of arrival.
    	3. Fair in Order: Every process gets a chance to execute in the exact order they arrive.


Disadvantages: <br>

	• Not Optimal for Time Sharing: Can lead to poor performance in interactive systems where response time is critical. <br>
 
    	• Convoy Effect: A single slow process can delay all other processes behind it, known as the "convoy effect.


<br><br>


## SJF

Shortest-Job-First (SJF) Scheduling is a process scheduling methodology used in computing environments. <br>
It selects the process that has the smallest execution time remaining, and runs it next. <br>


This approach optimizes the overall time required for executing all processes by minimizing the average waiting time for all processes. <br>

Disadvantages of SJF Scheduling: <br>

	Starvation: Longer processes may never execute if shorter processes keep arriving. This issue, known as starvation, is a significant drawback in environments where process times vary greatly.


	Problem ≡ Starvation – low priority processes may never execute 

	Solution ≡ Aging – as time progresses increase the priority of the process

 <br><br>

## Priority-based scheduling algorithm


less value high priority <br>

 <br><br>
## Round Robin 
Round Robin (RR) is a CPU scheduling method where each process gets a fixed time (quantum), typically 10-100 milliseconds. After its time ends, it goes to the end of the queue. The performance depends on the size of the quantum: a large quantum makes RR similar to FIFO, while a very small one can cause high overhead due to frequent switching between processes.

 <br><br>


## Multilevel Queue

Definition: The ready queue is divided into multiple fixed queues, each dedicated to a specific type of process (e.g., foreground for interactive processes, background for batch processes). Processes are permanently assigned to one queue based on their type. <br>

Key Characteristics: <br>

	Each queue has its own scheduling algorithm:
	Foreground: Round Robin (RR)
	Background: First-Come, First-Served (FCFS)
	Inter-Queue Scheduling:
	Fixed Priority: Higher priority for foreground; can lead to background process starvation.
	Time Slice: CPU time divided among queues (e.g., 80% for foreground, 20% for background).

<br><br>
## Multilevel Feedback Queue
Definition: An advanced version of the multilevel queue where processes can move between queues based on their behavior and requirements. Aging can be used to prevent starvation. <br>

Key Characteristics: <br>

	Dynamic Movement: Processes may be promoted or demoted across queues.
	Parameters:
	Number of queues.
	Scheduling algorithm for each queue.
	Criteria for promotion, demotion, and initial queue assignment.
	Flexible and adaptive, ensuring a balance between CPU and I/O-bound processes.


 <img src="chapters/pics/multilevel.jpg" alt="Four Components of OS" width="400"> <br> <br>
