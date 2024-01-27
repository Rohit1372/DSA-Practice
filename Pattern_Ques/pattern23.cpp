#include<bits/stdc++.h>
using namespace std;

/* 
1234
 234
  34
   4
    */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int space=1;
        while(space<i){
            cout<<" ";
            space++;
        }
        int j=i;
        while(j<=n){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}