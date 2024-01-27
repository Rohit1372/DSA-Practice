#include<bits/stdc++.h>
using namespace std;

/* 
    1
   22
  333
 4444
55555
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
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}