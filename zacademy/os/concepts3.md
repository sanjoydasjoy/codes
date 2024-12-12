## Classical Problems of Synchronization


 <img src="chapters/pics/bounded_buffer.png" alt="Four Components of OS" width="500"> <br> <br>

  <img src="chapters/pics/bounded_buffer2.png" alt="Four Components of OS" width="500"> <br> <br>

  <img src="chapters/pics/bounded_buffer3.png" alt="Four Components of OS" width="500"> <br> <br>

<br><br>







Round Robin (RR) is a CPU scheduling method where each process gets a fixed time (quantum), typically 10-100 milliseconds. After its time ends, it goes to the end of the queue. The performance depends on the size of the quantum: a large quantum makes RR similar to FIFO, while a very small one can cause high overhead due to frequent switching between processes.

 <br><br>



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

