#include<bits/stdc++.h>
using namespace std;

//Approach 1st with queue as extra space 

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    //q.push(19);

    queue<int> newQ;

    while(newQ.size() != q.size()){
        int val = q.front();
        newQ.push(val);
        q.pop();
    }

    while(!newQ.empty()){
        int val1 = newQ.front();
        q.push(val1);
        newQ.pop();

        int val2 = q.front();
        q.push(val2);
        q.pop();

    }

    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }

}