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
    Is it possible to sort an array in just one pass without reccuring swaps?
*/
bool merge(vi &arr, int s,int mid, int e){
    if(arr[mid]>arr[mid+1]){
        int t= arr[mid];
        arr[mid]=arr[mid+1];
        arr[mid+1]=t;
    }  
    for(int i=s;i<e;i++){
        if(arr[i]>arr[i+1])return 1;
    }
    return 0;
}

bool sort(vi &arr,int s, int e){
    int size=e-s+1;
    if(size==1){
        return 0;
    }
    int mid =(s+e)/2;
    bool a= sort(arr,s, mid);
    bool b= sort(arr,mid+1,e);
    bool c=merge(arr,s,mid,e);
    if(a||b||c){
        return 1;
    }
    else return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vi arr(n);
        REP(i,0,n)cin>>arr[i];
        if(sort(arr,0,n-1)){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}