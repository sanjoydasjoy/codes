## CPU Scheduling

The dispatcher is a component of the operating system that switches control from the OS to a user process. <br>

The key functions of the dispatcher include: <br>

    1.Context Switching: Saving the state of the currently running process and loading the state of the next scheduled process.

    2.Switching to User Mode: Changing the mode of operation from kernel mode (where the OS executes) to user mode (where the user process runs).

    3.Jumping to the Correct Location: Ensuring the process resumes from the correct point within its program.

**Dispatch Latency** is the time it takes for the dispatcher to switch from one process to another. This includes the time for all the above steps and represents the overhead involved in process switching. <br>
