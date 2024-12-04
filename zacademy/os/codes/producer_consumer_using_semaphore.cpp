#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>

using namespace std;

struct BinarySemaphore
{
  mutex mtx;
  condition_variable cv;
  bool flag;

  BinarySemaphore() : flag(false) {}

  void acquire()
  {
    unique_lock<mutex> lock(mtx);
    while (flag)
    {
      cv.wait(lock);
    }
    flag = true;
  }

  void release()
  {
    lock_guard<mutex> lock(mtx);
    flag = false;
    cv.notify_one();
  }
};

BinarySemaphore semaphore;

const int BUFFER_SIZE = 5;
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int counter = 0;

void producer(int produce_count)
{
  for (int i = 1; i <= produce_count; ++i)
  {
    int item = i;
    while (true)
    {
      semaphore.acquire();
      if (counter < BUFFER_SIZE)
      {
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        counter++;
        cout<<"Producer produced an item "<< item<<". Buffer count: "<<counter<<endl;
        semaphore.release();
        break;
      }
      else
      {
        cout << "Buffer is full. Producer is waiting"<<endl;
        semaphore.release();
        this_thread::sleep_for(chrono::milliseconds(10));
      }
    }
    this_thread::sleep_for(chrono::milliseconds(100));
  }
}

void consumer(int consume_count)
{
  for (int i = 1; i <= consume_count; ++i)
  {
    int item;
    while (true)
    {
      semaphore.acquire();
      if (counter > 0)
      {
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        counter--;
        cout<<"Consumer consumed an item "<<item<<". Buffer count: "<<counter<<endl;
        semaphore.release();
        break;
      }
      else
      {
        cout << "Buffer is empty. Consumer is waiting " << endl;
        semaphore.release();
        this_thread::sleep_for(chrono::milliseconds(10));
      }
    }
    this_thread::sleep_for(chrono::milliseconds(150));
  }
}

int main()
{
  thread prod1(producer, 10);
  thread cons1(consumer, 10);

  prod1.join();
  cons1.join();

  cout << "Producer-Consumer with Bounded Buffer Scheme completed." << endl;

  return 0;
}
