#include<bits/stdc++.h>
using namespace std;

/* 
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int space=1;
        while(space<=n-i){
            cout<<" ";
            space++;
        }
        int j=1;
        while(j<=i){
            cout<<j;
            j++;
        }
        int val = i-1;
        while(val>0){
            cout<<val;
            val--;
        }
        cout<<endl;
        i++;
    }
}