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
    Taj Mahal: Binary search problem
*/



int main(){
    int n,ans;
    cin>>n;
    vi p(n);
    REP(i,0,n)cin>>p[i];
    vi q(n);
    REP(i,0,n){
        int turn=0;
        if(p[i]>i){
            if((p[i]-i)%n==0){
                turn = p[i];
            }
            else{
                turn= (((p[i]-i)/n)+1)*n + i;
            }
        }
        else{
            turn=i;
        }
        q[i]=turn;
    }
    ans=*min_element(q.begin(),q.end());
    cout<<ans<<"\n";
    return 0;
}