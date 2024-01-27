#include<bits/stdc++.h>
using namespace std;

/* 
A A A
B B B
C C C
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        char ch = 'A'+i-1;
        while(j<=n){
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}