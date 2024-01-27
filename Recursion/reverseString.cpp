#include <bits/stdc++.h>
using namespace std;

void reverseString(string str, int start, int end)
{
    if (start >= end)
    {
        cout << "result : " << str << endl;
        return;
    }
    int temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

int main()
{
    string str = "abcdefg";
    int size = str.length();
    reverseString(str, 0, size - 1);
};