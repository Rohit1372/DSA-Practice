#include <bits/stdc++.h>
using namespace std;

void solve(int num, string arr[])
{
    if (num == 0)
    {
        return;
    }
    int n = num % 10;

    solve(num / 10, arr);
    cout << arr[n] << " ";
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    cout << "Enter number : ";
    cin >> num;
    solve(num, arr);
}