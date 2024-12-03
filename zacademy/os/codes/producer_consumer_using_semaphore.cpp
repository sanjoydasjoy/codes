#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <vector>
#include <unistd.h>

using namespace std;

const int BUFFER_SIZE = 5;

// Shared buffer and control variables
vector<int> buffer(BUFFER_SIZE);
int in = 0;
int out = 0;

// Renamed semaphores to avoid naming conflicts
sem_t empty_slots;
sem_t full_slots;
mutex mtx;

// Producer function to add items to the buffer
void produce(int item) {
    sem_wait(&empty_slots); // Wait for an empty slot
    mtx.lock();
    buffer[in] = item;
    cout << "Producer Produced item no. : " << item << endl;
    in = (in + 1) % BUFFER_SIZE; // Circular buffer
    mtx.unlock();
    sem_post(&full_slots); // Signal a full slot
}

// Consumer function to remove items from the buffer
void consume() {
    sem_wait(&full_slots); // Wait for a full slot
    mtx.lock();
    int item = buffer[out];
    cout << "Consumer Consumed item no. : " << item << endl;
    out = (out + 1) % BUFFER_SIZE; // Circular buffer
    mtx.unlock();
    sem_post(&empty_slots); // Signal an empty slot
}

// Producer thread function
void producer() {
    for (int i = 0; i < 5; ++i) {
        produce(i);
        sleep(1); // Simulate production time
    }
}

// Consumer thread function
void consumer() {
    for (int i = 0; i < 5; ++i) {
        consume();
        sleep(2); // Simulate consumption time
    }
}

int main() {
    // Initialize semaphores
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);

    // Create threads
    thread producer_thread(producer);
    thread consumer_thread(consumer);

    // Wait for threads to complete
    producer_thread.join();
    consumer_thread.join();

    // Destroy semaphores
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    return 0;
}
