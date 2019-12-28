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
   Problem: To find the minimum of odd and even number of numbers.
*/

int main(){
    int n,o=0,e=0,x;
    cin>>n;
    REP(i,0,n){
        cin>>x;
        if(x%2==0)e++;
        else o++;
    }
    cout<<min(o,e)<<endl;
    return 0;    
}