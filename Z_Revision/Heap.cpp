// Heap is a complete binary tree(CBT) thats come with a heap order property
// CBT - means every level completely filled except last level
// nodes always added from the left

// Insertion in heap Time complexity : O(logn)
// Deletion in heap Time complexity : O(logn)
// SOrt in heap Time complexity : O(N logn)

#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(50);
    h.insert(55);

    h.deletefromHeap();
    h.deletefromHeap();

    h.print();

    int arr[] = {
        -1, 54, 53, 55, 52, 50};
    int n = 5;

    cout << endl;
    cout << "Before heapify : " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << endl;
    cout << "After heapify : " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    heapSort(arr, n);

    cout << "After Sorted : " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}