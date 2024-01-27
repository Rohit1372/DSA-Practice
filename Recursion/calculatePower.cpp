#include <bits/stdc++.h>
using namespace std;

int calculatePower(int num1, int num2)
{

    if (num2 == 0)
    {
        return 1;
    }
    if (num2 == 1)
    {
        return num1;
    }

    int ans = num1 * calculatePower(num1, num2 - 1);

    return ans;
}

int main()
{
    int num1, num2;
    cout << "Enter number : ";
    cin >> num1 >> num2;

    cout << "Output is : " << calculatePower(num1, num2);
}