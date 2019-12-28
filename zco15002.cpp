#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//General functionality help
#define REP(i,a,b) for(int i=a;i<b;i++)

//Vector functionality help
typedef vector<int> vi;
/*
    Variation: Calculating the number of pairs with k differnce in an array. 
*/

int main(){
    int n,k,count=0;
    cin>>n>>k;
    vi p(n);
    REP(i,0,n)cin>>p[i];
    sort(p.begin(),p.end());
    for(int i=0,j=1;j<n;){
        int variation = p[j]- p[i];
        if(variation>=k){
            count+=(n-j);
            i++;
        }
        else{
            j++;
        } 
    }
    cout<<count;
    return 0;
}