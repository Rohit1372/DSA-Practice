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
        int j = 1;
        while(j<=n-i+1){
            cout<<"*";
            j++;
        }
        int space = 1;
        while(space<=i){
            cout<<" ";
            space++;
        }
        cout<<endl;
        i++;
    }
}