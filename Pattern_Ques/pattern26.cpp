#include<bits/stdc++.h>
using namespace std;

//dabangg pattern

/* 
1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1
 */

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){

        int j=1;
        while(j<=n-i+1){
            cout<<j<<" ";
            j++;
        }

        int star = (i-1)*2;
        while(star>0){
            cout<<"*"<<" ";
            star--;
        }

        int z=n-i+1;
        while(z>0){
            cout<<z<<" ";
            z--;
        }
        cout<<endl;
        i++;

    }
}