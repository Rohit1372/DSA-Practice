#include<bits/stdc++.h>
using namespace std;

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

    stack<int> s;

    while(s.size() != q.size()){
        s.push(q.front());
        q.pop();
    }

    int val = s.top();

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(q.front() != val){
        q.push(q.front());
        q.pop();
    }

    while(s.size() != q.size()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        int val1 = s.top();
        q.push(val1);
        s.pop();

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