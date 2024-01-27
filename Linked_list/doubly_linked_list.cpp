#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void deleteFromValue(Node *&head, Node *&tail, int value)
{
    if (head->data == value)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        // remove from memory
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }

        // Remove from memory
        curr->next = NULL;
        delete curr;
    }
}

void deleteFromPosition(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        // remove from memory
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 1;
        while (cnt != pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }

        // Remove from memory
        curr->next = NULL;
        delete curr;
    }
}

// Insertion

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
        head->prev = temp;
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
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtMiddle(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int cnt = 1;
    Node *curr = head;
    while (cnt < pos - 1)
    {
        curr = curr->next;
        cnt++;
    }

    if (curr->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;
}

void traverse(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL";
}

void traverseByTail(Node *&tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->prev;
    }
    cout << "NULL";
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtMiddle(head, tail, 25, 3);
    insertAtMiddle(head, tail, 5, 1);
    insertAtMiddle(head, tail, 50, 7);

    deleteFromValue(head, tail, 50);

    cout << "Head-> " << head->data << " ---- "
         << "Tail-> " << tail->data << endl;

    traverse(head);
    cout << endl;
    traverseByTail(tail);
}