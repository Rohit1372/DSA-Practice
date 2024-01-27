#include <bits/stdc++.h>
using namespace std;

// STL  -> deque<int> q

class Dequeue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_front(int ele)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = ele;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = ele;
        }
        else
        {
            front--;
            arr[front] = ele;
        }
    }

    void push_back(int ele)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = ele;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = ele;
        }
        else
        {
            rear++;
            arr[rear] = ele;
        }
    }

    void pop_front()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue if empty" << endl;
        }
        int val = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void pop_back()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue if empty" << endl;
        }
        int val = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
};

int main()
{
    Dequeue dq(5);
}