#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef vector<int> vi;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define PB push_back
#define VOUT(p) for(auto x:p) cout<<x<<" ";

/*
   Merge sort: Sorting algorithm with the highest efficency. O(n lg(n))
   I'll apply this recursively to sort on a vector.
*/
void merge(vi &p, int start, int mid, int end);

void merge_sort(vi &p, int start, int end){
    int size=end-start;
    if(size<=0){
        return;
    }
    int mid=(start+end)/2;
    merge_sort(p,start,mid);
    merge_sort(p,mid+1,end);
    merge(p,start,mid,end);
    return;
}

void merge(vi &p, int start, int mid, int end){    
    vi x;
    int i=start,j=mid+1,k;
    for(k=0;i<=mid && j<=end;k++){
        if(p[i]<=p[j]){
            x.PB(p[i]);
            i++;
        }
        else {
            x.PB(p[j]);
            j++;
        }
    }
    if(j<=end){
        for(;j<=end;j++){
            x.PB(p[j]);
        }
    }
    else if(i<=mid){
        for(;i<=mid;i++){
            x.PB(p[i]);
        }
    }

    for(int i=0, j=start;j<=end;i++,j++){
        p[j]=x[i];
    }
}

int main(){
    vi p;
    int n;
    cin>>n;
    REP(i,0,n){
        int x;
        cin>>x;
        p.PB(x);
    }
    merge_sort(p,0,p.size()-1);
    VOUT(p);
    cout<<endl;
    return 0;
}