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
        cout << "Memory is freed with the data -> " << value << endl;
    }
};

// DELETE NODE FROM VALUE

void deleteNodeFromValue(Node *&head, Node *&tail, int value)
{

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        // Remove from memory
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr->next == NULL)
        {
            tail = prev;
        }
        // Remove from memory
        curr->next = NULL;
        delete curr;
    }
}

// DELETION from position

void deleteNodeFromPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // Remove from memory
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 1;
        while (cnt != position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        Node *temp = curr;
        prev->next = curr->next;
        if (temp->next == NULL)
        {
            tail = prev;
        }
        // Remove from memory
        curr->next = NULL;
        delete curr;
    }
}

// INSERTION

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        head = tail;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtMiddle(Node *&head, Node *&tail, int data, int k)
{
    // Insert at head
    if (k == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int count = 1;
    Node *temp = head;

    while (count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    // Insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
}

void traverse(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtMiddle(head, tail, 25, 3);
    insertAtMiddle(head, tail, 5, 1);
    insertAtMiddle(head, tail, 50, 7);

    // deleteNodeFromPosition(head, tail, 5);

    deleteNodeFromValue(head, tail, 5);

    cout << "Head-> " << head->data << " ---- "
         << "Tail-> " << tail->data << endl;

    traverse(head);
}