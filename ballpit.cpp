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
    Finding minimum k for which Mr.Sharma gets more than half the total balls
    tags: binary search
*/

bool check(int n, int k){
    int sh=0, si=0;
    int init=n;
    while(n>=k){
        sh+=k; 
        n-=k;
        si+=n/10;
        n-=(n/10);
    }
    sh+=n; n=0;
    if(sh > (init/2)){
        return 1;
    }
    else return 0;
}

void min(int n){
    int s=1, e=n/10;
    if(e==0){
        cout<<1<<endl;
        return;
    }
    int m;
    int val=e;
    while(e>=s){
        // cout<<"\n"<<s<<e<<"\n";
        m=(s+e)/2;
        if(check(n,m)){
            if(val>m)val=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    cout<<val<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    min(n);
    return 0;
}