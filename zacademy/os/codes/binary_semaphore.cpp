#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

class BinarySemaphore {
private:
    mutex mtx;              // synchronization primitive that protects shared resources 
                            //from being accessed simultaneously by multiple threads
    condition_variable cv;  // object that will be used to block or wake up threads.
    bool flag;

public:
    BinarySemaphore() : flag(false) {} // constructor initializes the flag to false

    void acquire() {
        unique_lock<mutex> lock(mtx);
        while (flag) {
            cv.wait(lock);
        }
        flag = true;
    }

    void release() {
        lock_guard<mutex> lock(mtx);
        flag = false;
        cv.notify_one();
    }
};

BinarySemaphore semaphore;

void P0() {
    semaphore.acquire();
    cout << "P0 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));

    cout << "P0 is finished.\n";
    semaphore.release();
}

void P1() {
    semaphore.acquire();
    cout << "P1 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));

    cout << "P1 is finished.\n";
    semaphore.release();
}

void P2() {
    semaphore.acquire();
    cout << "P2 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));

    cout << "P2 is finished.\n";
    semaphore.release();
}

void P3() {
    semaphore.acquire();
    cout << "P3 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));

    cout << "P3 is finished.\n";
    semaphore.release();
}

int main() {
    thread t0(P0);
    thread t1(P1);
    thread t2(P2);
    thread t3(P3);

    t0.join();
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
