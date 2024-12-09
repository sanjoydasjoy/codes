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
