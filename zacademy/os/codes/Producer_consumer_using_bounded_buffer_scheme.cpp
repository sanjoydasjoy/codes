#include <iostream>
#include <thread>
#include <chrono>

const int BUFFER_SIZE = 5;

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int counter = 0;

bool flag[2] = {false, false};
int turn = 0;

void producer(int produce_count)
{
    int i = 0; // Producer's index
    int j = 1; // Consumer's index

    while (produce_count--)
    {
        flag[i] = true;
        turn = j;
        while (flag[j] && turn == j)
            ;

        if (counter < BUFFER_SIZE)
        {
            buffer[in] = 1;
            in = (in + 1) % BUFFER_SIZE;
            /*circular indexing*/
            counter++;
            std::cout << "Producer produced an item. Buffer count: " << counter << std::endl;
        }
        else
        {
            std::cout << "Producer is waiting. Buffer is full.\n";
        }

        flag[i] = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(int consume_count)
{
    int i = 1; // Consumer's index
    int j = 0; // Producer's index

    while (consume_count--)
    {
        flag[i] = true;
        turn = j;
        while (flag[j] && turn == j)
            ;

        if (counter > 0)
        {
            int item = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            counter--;
            std::cout << "Consumer consumed an item " << item << ". Buffer count: " << counter << std::endl;
        }
        else
        {
            std::cout << "Consumer is waiting. Buffer is empty.\n";
        }

        flag[i] = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main()
{
    std::thread prod(producer, 10);
    std::thread cons(consumer, 10);
    prod.join();
    cons.join();
    std::cout << "Producer-Consumer with Bounded Buffer Scheme completed." << std::endl;
    return 0;
}

/*
g++ Producer_consumer_using_bounded_buffer_scheme.cpp -o p
*/
