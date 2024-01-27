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
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed with the value -> " << value << endl;
    }
};

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is not empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void insertNode(Node *&tail, int ele, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        tail->next = tail;
    }
    else
    {
        Node *temp = tail;
        while (temp->data != ele)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void traverse(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != tail);
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 0, 10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 20, 40);

    deleteNode(tail, 40);

    traverse(tail);
}