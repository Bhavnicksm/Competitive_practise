#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//General functionality help
#define REP(i,a,b) for(int i=a;i<b;i++)

//Vector functionality help
typedef vector<int> vi;

/*
    Momo market: Calculating the number of momos we can buy of n shops with q money.
*/

int main(){
    int n,m;
    cin>>n;
    vi p(n);
    REP(i,0,n)cin>>p[i];
    cin>>m;
    vi q(m);
    REP(i,0,m)cin>>q[i];

    int count=0;
    REP(i,0,n){
        count+=p[i];
        p[i]=count;
    }
    REP(i,0,m){
        auto x1=upper_bound(p.begin(),p.end(),q[i]);
        auto x2=x1-1;
        int pos= (x2-p.begin()) + 1;
        cout<<pos<<" "<<q[i]-(*x2)<<endl;
    }
    return 0;
}