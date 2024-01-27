#include<bits/stdc++.h>
using namespace std;

/* 
*****
 ****
  ***
   **
    *
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int space = 1;
        while(space<i){
            cout<<" ";
            space++;
        }
        int j=1;
        while(j<=n-i+1){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}