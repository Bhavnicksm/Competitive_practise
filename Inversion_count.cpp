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
   Inversion Count: To count the number of inversions in nlogn time.
*/

int merge(vi &p, int f, int m, int l){
    vi x;
    int  i=f,j=m+1;
    int count=0;
    while(i<=m && j<=l){
        if(p[i]>=p[j]){
            count+=(m-i+1);
            x.PB(p[j]);
            j++;
        }
        else{
            x.PB(p[i]);
            i++;
        }
    }
    while(i<=m){
        x.PB(p[i]);
        i++;
    }
    while(j<=l){
        x.PB(p[j]);
        j++;
    }
    for(int k=f,a=0;k<=l;k++,a++){
        p[k]=x[a];
    }
    return count;
}

int inversion(vi &p,int f,int l){
   int m=(f+l)/2 ;
   if(f==l){
       return 0;
   }
   int a= inversion(p,f,m);
   int b= inversion(p,m+1,l);
   int c= merge(p,f,m,l);
//    cout<<c<<"\n";
   return (a+b+c);
}

int main(){
    int size; cin>>size;
    vi arr(size);
    REP(i,0,size)cin>>arr[i];
    cout<<inversion(arr,0,size-1)<<"\n";
    return 0;
}