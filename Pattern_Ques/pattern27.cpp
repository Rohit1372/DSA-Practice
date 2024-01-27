#include<bits/stdc++.h>
using namespace std;

/* 
      *
    * * * 
  * * * * *
* * * * * * *
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
        int j=(i*2)-1;
        while(j>0){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }
}