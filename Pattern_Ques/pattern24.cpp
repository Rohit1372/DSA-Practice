#include<bits/stdc++.h>
using namespace std;

/* 
   1
  23
 456
78910
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    int count=1;
    while(i<=n){
        int space=1;
        while(space<=n-i){
            cout<<" ";
            space++;
        }
        int j=1;
        while(j<=i){
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}