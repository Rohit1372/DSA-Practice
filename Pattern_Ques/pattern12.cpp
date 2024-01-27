#include<bits/stdc++.h>
using namespace std;

/* 
1 2 3
2 3 4
3 4 5
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int val = i;
        while(j<=n){
            cout<<val<<" ";
            j++;
            val++;
        }
        cout<<endl;
        i++;
    }
}