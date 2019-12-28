#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


#define REP(i,a,b) for(int i=a;i<b;i++)
#define PB push_back
#define MP make_pair

/*
   TSORT: beginner question from codeschef
   using vectors to take inputs and sorting values.
*/

int main(){
    int a,b;
    cin>>a;
    vi p;
    REP(i,0,a){
        cin>>b;
        p.PB(b);
    }
    sort(p.begin(),p.end());
    for(auto x:p){
        cout<<x<<" ";
    }
}