#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//General functionality help
typedef long long ll;
#define REP(i,a,b) for(int i=a;i<b;i++)

//Vector functionality help
typedef vector<int> vi;
#define PB push_back
#define VOUT(p) for(auto x:p) cout<<x<<" "; 

typedef pair<int,int> pi;

#define MP make_pair

/*
   Finding value of X^n
*/

ll power(int x, int n){
    if(n==0){
        return 1;
    }
    else if(n==1){
        return x;
    }
    int mid = n/2;
    ll a= power(x,mid);
    ll b= power(x,n-mid);
    return a*b;
}


int main(){
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
    return 0;
}