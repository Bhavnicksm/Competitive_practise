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
   Chef Restaurant: Checking the timings of the hotel to make a booking there.
*/


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pi> p;
        REP(i,0,n){
            int x,y;
            cin>>x>>y;
            p.PB(MP(x,y));
        }
        cout<<"\n";
        sort(p.begin(),p.end());
        vi t(m);
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            auto one=lower_bound(p.begin(),p.end(),MP(x,0));
            auto two=one-1;
            if((*two).second>x)cout<<0<<"\n";
            else if(one==p.end())cout<<-1<<"\n";
            else{
                cout<<(*one).first - x<<"\n";
            }
        }
    }
    return 0;
}