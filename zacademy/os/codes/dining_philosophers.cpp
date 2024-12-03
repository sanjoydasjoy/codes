#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

const int num_philosophers = 5;
mutex forks[num_philosophers];
mutex output_mutex; // Mutex for synchronizing output

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % num_philosophers;

    // To avoid deadlock, we ensure that the philosopher with the highest ID picks up the left fork first
    if (id == num_philosophers - 1) {
        forks[right_fork].lock();
        forks[left_fork].lock();
    } else {
        forks[left_fork].lock();
        forks[right_fork].lock();
    }

    // Synchronize output
    {
        lock_guard<mutex> lock(output_mutex);
        cout << "Philosopher " << id << " is eating.\n";
    }

    // Release the forks
    forks[left_fork].unlock();
    forks[right_fork].unlock();

    // Synchronize output
    {
        lock_guard<mutex> lock(output_mutex);
        cout << "Philosopher " << id << " is thinking.\n";
    }
}

int main() {
    thread philosophers[num_philosophers];

    // Create threads for each philosopher
    for (int i = 0; i < num_philosophers; ++i) {
        philosophers[i] = thread(philosopher, i);
    }

    // Join threads
    for (int i = 0; i < num_philosophers; ++i) {
        philosophers[i].join();
    }

    return 0;
}
