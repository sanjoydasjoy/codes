#include <bits/stdc++.h>

using namespace std;

class CountingSemaphore {
private:
    mutex mtx;
    condition_variable cv;
    int count;

public:
    CountingSemaphore(int initialCount) : count(initialCount) {}

    void acquire() {
        unique_lock<mutex> lock(mtx);
        while (count <= 0) {
            cv.wait(lock);
        }
        count--;
    }

    void release() {
        lock_guard<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

CountingSemaphore semaphore(1); // Initialize with desired initial count

void P0() {
    semaphore.acquire();
    cout << "Process-0 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Process-0 is finished.\n";
    semaphore.release();
}

void P1() {
    semaphore.acquire();
    cout << "Process-1 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Process-1 is finished.\n";
    semaphore.release();
}

void P2() {
    semaphore.acquire();
    cout << "Process-2 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Process-2 is finished.\n";
    semaphore.release();
}

void P3() {
    semaphore.acquire();
    cout << "Process-3 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Process-3 is finished.\n";
    semaphore.release();
}

void P4() {
    semaphore.acquire();
    cout << "Process-4 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Process-4 is finished.\n";
    semaphore.release();
}

void P5() {
    semaphore.acquire();
    cout << "Process-5 is executing.\n";
    // Critical section
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Process-5 is finished.\n";
    semaphore.release();
}

int main() {
    thread t0(P0);
    thread t1(P1);
    thread t2(P2);
    thread t3(P3);
    thread t4(P4);
    thread t5(P5);

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
