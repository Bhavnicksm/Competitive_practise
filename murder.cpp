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
   Murder: another merge sort technique problem
*/

int merge(vi &p, int start, int mid, int end){
    vi x;
    int i=start, j=mid+1,count=0;
    while(i<=mid && j<=end){
        if(p[j]>p[i]){
            count+= (p[i]*(end-j+1));
            x.PB(p[i]);
            i++;
        }
        else{
            x.PB(p[j]);
            j++;
        }
    }
    if(j>end){
        while(i<=mid){
            x.PB(p[i]);
            i++;
        }
    }
    else{
        while(j<=end){
            x.PB(p[j]);
            j++;
        }
    }
    for(int k=start,l=0;k<=end;k++,l++){
        p[k]=x[l];
    }
    return count;
}

int calc(vi &p,int start, int end){
    int m=(start+end)/2;
    if(start==end){
        return 0;
    }
    int a=calc(p,start,m);
    int b=calc(p,m+1,end);
    int c=merge(p,start,m,end);
    return (a+b+c);
}




int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi p(n);
        REP(i,0,n)cin>>p[i];
        cout<<calc(p,0,n-1);
    }
    return 0;
}