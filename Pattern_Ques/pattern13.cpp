#include<bits/stdc++.h>
using namespace std;

/* 
A B C
B C D
C D E
 */

int main(){
    /* int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int val = i;
        while(j<=n){
            char ch = 'A'+val-1;
            cout<<ch<<" ";
            j++;
            val++;
        }
        cout<<endl;
        i++;
    } */
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A'+i+j-2;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}