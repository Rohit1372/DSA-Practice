#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int size;
    int *arr;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Insert in to queue
    void enqueue(int ele)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = ele;
            rear++;
        }
    }

    // delete from queue
    void dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    // Get front element queue
    void getFront()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Front element is : " << arr[front] << endl;
        }
    }

    // Check queue is empty is not
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Before deqeue -> ";
    q.getFront();

    q.dequeue();

    cout << "After deqeue -> ";
    q.getFront();

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}