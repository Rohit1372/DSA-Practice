#include <bits/stdc++.h>
using namespace std;

int fact(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    int ans = 1;

    ans = num * fact(num - 1);
    return ans;
}

int main()
{
    int num;
    cout << "Enter number : ";
    cin >> num;
    cout << "Output is : " << fact(num);
}