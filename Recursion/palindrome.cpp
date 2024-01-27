#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    else
    {
        return isPalindrome(str, start + 1, end - 1);
    }
}

int main()
{
    string str;
    cout << "Enter string : ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1))
        cout << "Palindrome";
    else
        cout << "not";
}