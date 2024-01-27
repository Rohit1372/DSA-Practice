#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Memory deleted with the value : " << value << endl;
    }
};

class Stack
{
public:
    int size;
    int top;
    Node *head;
    Node *tail;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        head = NULL;
        tail = NULL;
    }

    // Push in stack
    void push(int ele)
    {
        if (top < size - 1)
        {
            if (head == NULL)
            {
                head = new Node(ele);
                tail = head;
            }
            else
            {
                Node *newNode = new Node(ele);
                tail->next = newNode;
                tail = newNode;
            }
            top++;
            cout << "Element inserted with " << tail->data << " at " << top << endl;
        }
        else
        {
            cout << "Stack is overflow" << endl;
        }
    }

    // poped in stack
    void pop()
    {
        if (tail != NULL && top >= 0)
        {
            if (top > 0)
            {
                Node *temp = head;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                temp->next = tail->next;
                delete tail;
                tail = temp;
            }
            else
            {
                Node *temp = tail;
                delete temp;
                head = tail = NULL;
            }
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    // get top ele in stack
    void peek()
    {
        if (tail != NULL)
        {
            int value = tail->data;
            cout << "Top element is : " << value << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    // check stack is empty or not
    bool isEmpty()
    {
        if (head == NULL)
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
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Before element poped -> ";
    st.peek();

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << "After element poped -> ";
    st.peek();
}