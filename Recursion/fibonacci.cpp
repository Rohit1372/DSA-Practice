#include <bits/stdc++.h>
using namespace std;

int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    int ans = fibonacci(num - 1) + fibonacci(num - 2);
    return ans;
}

int main()
{
    int num;
    cout << "Enter number : ";
    cin >> num;
    cout << fibonacci(num) << " ";
}