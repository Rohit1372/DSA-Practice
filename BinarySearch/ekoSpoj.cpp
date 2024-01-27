#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            sum += arr[i] - mid;
        }
    }

    if (sum >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solve(int arr[], int n, int m)
{
    /*
        TC -> O(N*M)
        int end = *max_element(arr, arr + n);

        int ans = -1;

        for (int i = 1; i <= end; i++)
        {
            if (isPossible(arr, n, m, i))
            {
                ans = i;
            }
        }

        return ans;

     */

    // TC -> O(N*logn)
    int start = 0;
    int end = *max_element(arr, arr + n);

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 4;
    int arr[n] = {20, 15, 10, 17};
    int m = 7;
    cout << "Our Answer will be : " << solve(arr, n, m);
}