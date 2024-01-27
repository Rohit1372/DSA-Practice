#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int np, int mid)
{

    int prata = 0;

    for (int i = 0; i < n; i++)
    {
        int R = arr[i];
        int j = 1;
        int time = 0;
        while (true)
        {
            if (time + j * R <= mid)
            {
                prata++;
                time += j * R;
                j++;
            }
            else
            {
                break;
            }
        }
        if (prata >= np)
        {
            return true;
        }
    }

    return false;
}

int solve(int arr[], int n, int np)
{

    int start = 0;
    int highest = *max_element(arr, arr + n);
    int end = highest * (np * (np + 1) / 2);

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, np, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n = 4;
    int arr[n] = {1, 2, 3, 4};
    int np = 10;
    cout << "Our Answer will be : " << solve(arr, n, np);
}