**chapter 6**

## Producer Consumer Problem


<img src="chapters/pics/producer_consumer.png" alt="Four Components of OS" width="500"> <br> <br>


## Race Condition

Race Condition: A race condition occurs when two or more processes access a shared resource and attempt to modify it simultaneously, leading to unpredictable or incorrect results. <br>

It happens when processes do not follow proper synchronization. <br>


<img src="chapters/pics/race_condition.png" alt="Four Components of OS" width="400"> <br> <br>

## Critical Section

A critical section in an operating system is a segment of code or a region of a program that accesses shared resources (variables, files, or data structures) and must not be accessed by more than one process at the same time. This is crucial to prevent data inconsistency or race conditions. <br>
Each process must ask permission to enter critical section in entry section, may follow critical section with exit section, then remainder section <br>

<img src="chapters/pics/critical.png" alt="Four Components of OS" width="350"> <br> <br>


## Solution to Critical-Section Problem

    1. Mutual Exclusion: If a process executing in its critical section,no other processes can be executing in their c. sections
    
    2. Progress: If no process is executing in its critical section and there exist some processes that wish to enter their 
       critical section,then the selection of processes that will enter the critical section next can't be postponed indefinitely
                  
    3. Bounded Waiting: A bound must exist on the number of times that other processes are allowed to enter their critical 
       sections after a process has made a request to enter its critical section and before that request is granted


 <br><br>      

### Peterson's Solution (Humble algorithm)

<img src="chapters/pics/peterson1.png" alt="Four Components of OS" width="500"> <br> <br>
<img src="chapters/pics/peterson2.png" alt="Four Components of OS" width="500"> <br> <br>
<img src="chapters/pics/peterson3.png" alt="Four Components of OS" width="500"> <br> <br>
**Peterson's Algorithm satisfies all three conditions of synchronization**
<img src="chapters/pics/peterson4.png" alt="Four Components of OS" width="500"> <br> <br>


### test_and_set lock Solution

**Atomic operation: A single operation that cannnot be interrupted by anyone**

<img src="chapters/pics/testset1.png" alt="Four Components of OS" width="500"> <br> <br>
<img src="chapters/pics/testset2.png" alt="Four Components of OS" width="500"> <br> <br>
<img src="chapters/pics/testset3.png" alt="Four Components of OS" width="500"> <br> <br>


Test-and-Set Lock provides Mutual Exclusion and ensures Progress, but it does not inherently guarantee Bounded Waiting. This limitation arises because processes may experience starvation due to its reliance on busy-waiting. To achieve Bounded Waiting, further mechanisms like priority-based scheduling or fairness algorithms are necessary.

<br> <br><br> 

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
