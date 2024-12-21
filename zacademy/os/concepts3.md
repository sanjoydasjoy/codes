## Producer Consumer Problem


<img src="chapters/pics/producer_consumer.png" alt="Four Components of OS" width="500"> <br> <br>


## Race Condition

Race Condition: A race condition occurs when two or more processes access a shared resource and attempt to modify it simultaneously, leading to unpredictable or incorrect results. <br>

It happens when processes do not follow proper synchronization. <br>


<img src="chapters/pics/race_condition.png" alt="Four Components of OS" width="400"> <br> <br>

## Critical Section

A critical section in an operating system is a segment of code or a region of a program that accesses shared resources (variables, files, or data structures) and must not be accessed by more than one process at the same time. This is crucial to prevent data inconsistency or race conditions. <br>
Each process must ask permission to enter critical section in entry section, may follow critical section with exit section, then remainder section

<img src="chapters/pics/critical.png" alt="Four Components of OS" width="400"> <br> <br>

## Classical Problems of Synchronization: 

**Bounded-Buffer Problem** <br><br>


 <img src="chapters/pics/bounded_buffer.png" alt="Four Components of OS" width="500"> <br> <br>

  <img src="chapters/pics/bounded_buffer2.png" alt="Four Components of OS" width="500"> <br> <br>

  <img src="chapters/pics/bounded_buffer3.png" alt="Four Components of OS" width="500"> <br> <br>

<br><br>

**The Readers Writers Problem** <br><br>

 <img src="chapters/pics/reader_writer1.png" alt="Four Components of OS" width="500"> <br> <br>

 <img src="chapters/pics/reader_writer2.png" alt="Four Components of OS" width="500"> <br> <br>

 <img src="chapters/pics/reader_writer3.png" alt="Four Components of OS" width="500"> <br> <br>

**Dining Philosophers Problem** <br><br>

 <img src="chapters/pics/dining1.png" alt="Four Components of OS" width="500"> <br> <br>

 <img src="chapters/pics/dining2.png" alt="Four Components of OS" width="500"> <br> <br>
