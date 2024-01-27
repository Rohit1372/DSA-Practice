#include<bits/stdc++.h>
using namespace std;

/* 
A 
B C 
C D E 
D E F G 
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int val=i;
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