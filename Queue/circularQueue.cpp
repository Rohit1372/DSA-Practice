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
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void enqueue(int ele)
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

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty" << endl;
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
        cout << "Element deleted with " << val << endl;
    }
};

int main()
{
    Queue q(5);

    // q.enqueue(60);
    q.enqueue(50);
    q.enqueue(40);
    q.enqueue(30);
    q.enqueue(20);
    q.enqueue(10);

    q.dequeue();
    q.dequeue();
    q.dequeue();
}

// #include<bits/stdc++.h>
// using namespace std;

// class Queue{
//     public:
//     int *arr;
//     int front;
//     int rear;
//     int size;

//     Queue(int size){
//         this->size = size;
//         arr = new int[size];
//         front = -1;
//         rear = -1;
//     }

//     void enqueue(int data){
//         if((front==0 && rear == size-1) || (rear == (front-1)%(size-1))){
//             cout<<"Queue is full"<<endl;
//         }
//         else if(front==-1 ){
//             front = 0;
//             rear =  0;
//             arr[rear] = data;
//         }
//         else if( front!=0 || rear == size-1){
//             rear = 0;
//             arr[rear] = data;
//         }
//         else{
//             rear++;
//             arr[rear] = data;
//         }
//     }

//     int dequeue(){
//         if(front == -1)
//         {
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }
//         int ans = arr[front];
//         arr[front] = -1;
//         if(front==rear)
//         {
//             front = -1;
//             rear = -1;
//         }
//         else if(front == size-1)
//         {
//             front = 0;
//         }else
//         {
//             front++;
//         }
//         return ans;
//     }

// };

// int main(){
//     Queue q(5);
//     q.enqueue(10);

// }