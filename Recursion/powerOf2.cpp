#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int ans = 2 * solve(n - 1);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << "Output is : " << solve(n);
}