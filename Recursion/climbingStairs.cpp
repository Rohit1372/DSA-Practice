#include <bits/stdc++.h>
using namespace std;

int solve(int num)
{

    if (num < 0)
    {
        return 0;
    }

    if (num == 0)
    {
        return 1;
    }

    int ans = solve(num - 1) + solve(num - 2);
    return ans;
}

int main()
{
    int num;
    cout << "Enter number : ";
    cin >> num;

    cout << "Output is : " << solve(num);
}
