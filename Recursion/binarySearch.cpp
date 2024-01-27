#include <bits/stdc++.h>
using namespace std;

void binarySearch(int arr[], int num, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (num == arr[mid])
    {
        cout << num << " FOunded at index of " << mid;
    }

    if (num < arr[mid])
    {
        binarySearch(arr, num, start, mid - 1);
    }
    else
    {
        binarySearch(arr, num, mid + 1, end);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num;
    cout << "Enter number : ";
    cin >> num;
    binarySearch(arr, num, 0, 9);
}