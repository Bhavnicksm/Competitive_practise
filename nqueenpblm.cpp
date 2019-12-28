#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Vector functionality help
typedef vector<int> vi;
#define PB push_back
#define VOUT(p) for(auto x:p) cout<<x<<" "; 


/*
   N queen Problem: To find the possible solutions to the placement positons of 
   n queens.

   Tags: Backtracking, reccursion.
*/

bool checker(int n, int m, int o, vi arr){
    //column check
    for(int i=0;i<m;i++){
        if(arr[n*i + o]==1)return 0;
        
    }
    //left diagnol check
    for(int i=m,j=o;i>=0 && j>=0; --i,--j){
        if(arr[n*i + j]==1)return 0;
    }
    //right diagnol check
    for(int i=m,j=o;i>=0 && j<n;--i,++j){
        if(arr[n*i + j]==1)return 0;
    }

    //else do this.
    return 1;
}

void reccursion(int n, int m, vi &arr){
    // cout<<"Flag"<<m<<" = ";
    // VOUT(arr);
    // cout<<"\n";
    
    if(m==n){
        // cout<<" ANS = ";
        VOUT(arr);
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(checker(n,m,i,arr)){
            arr[m*n+i]=1;
            reccursion(n,m+1,arr);
            arr[m*n+i]=0;
        }
    }
    return;

}

void nqueen(int n){
    vi arr(n*n,0);
    reccursion(n,0,arr);
}


int main(){
    int n;
    cin>>n;
    nqueen(n);
    return 0;
}