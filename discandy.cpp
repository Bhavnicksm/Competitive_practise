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
   Distribute candies: To distribute equal number of candies to k people
   each only taking out of one of N boxes.
*/

bool checker(vi p,int k,int a){
    int count=0;
    for(int i=0;i<p.size();){
        if(p[i]>=a){
            p[i]-=a;
            count++;
        }
        else{
            i++;
        }
        if(count==k){
            return 1;
        }
    }
    return 0;
}

int max_candy(vi p,int k){
    int max = *max_element(p.begin(),p.end());
    int mid, start=0, end=max;
    int val=0;
    while(start<=end){
        mid=(start+end)/2;
        if(checker(p,k,mid)){
            val=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return val;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vi p(n);
        REP(i,0,n)cin>>p[i];
        cout<<max_candy(p,k)<<"\n";
    }
}