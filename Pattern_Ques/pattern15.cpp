#include<bits/stdc++.h>
using namespace std;

/* 
A 
B C 
D E F 
G H I F
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    int val = 1;
    while(i<=n){
        int j=1;
        while(j<=i){
            char ch = 'A'+val-1;
            cout<<ch<<" ";
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}