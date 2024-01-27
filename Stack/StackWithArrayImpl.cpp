#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push in stack
    void push(int ele)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = ele;
            cout
                << "Element inserted with " << arr[top] << " at " << top << endl;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop in stack
    void pop()
    {
        if (top >= 0)
        {
            top--;
            cout << "Popped!!" << endl;
        }
        else
        {
            cout << "Stack is Underflow" << endl;
        }
    }

    // Get top ele in stack
    void peek()
    {
        if (top >= 0)
        {
            cout << "Top element is : " << arr[top] << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    // check stack ie empty or not
    bool isEmpty()
    {
        if (top == -1)
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

    cout << "After element poped -> ";
    st.peek();

    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}