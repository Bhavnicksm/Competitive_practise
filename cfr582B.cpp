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
   Bad prices: Checking if a number less than the current one exist in the array.
*/

int main(){
    int t,n;
    cin>>t;
    vi p[t];
    REP(i,0,t){
        cin>>n;
        int x;
        REP(j,0,n){
            cin>>x;
            p[i].PB(x);
        }
    }

    REP(i,0,t){
        n=p[i].size();
        int bday=0;
        int min=p[i][n-1];
        for(int j=n-1;j>=0;j--){
            if(min>=p[i][j])min=p[i][j];
            else bday++;        
        }
        cout<<bday<<endl;
    }
    return 0;
}