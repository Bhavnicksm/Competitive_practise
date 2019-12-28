#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define REP(i,a,b) for (int i = a;i<b; i++)
#define PB push_back
#define MP make_pair

/*
   FCTRL2: codechef beginner problem set question
   Computing large number factorials using array multiplication...
   Time: ~3hrs
*/

void multiply(vi &p, int n){
    int sum,carry=0;
    REP(i,0,(int)p.size()){
        sum=p[i]*n+carry;
        p[i]=sum%10;
        carry=sum/10;
    }
    while(carry!=0){
        // cout<<"Flag: "<<carry<<endl;
        p.PB(carry%10);
        carry/=10;
    } 
    // for(auto x:p){
    //     cout<<x<<" ";
    // }
}

void factorial(int n){
    vi a={1};
    REP(i,2,n+1){
        multiply(a,i);
    }
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<"\n";
}

int main(){
    int a,b=0;
    cin>>a;
    REP(i,0,a){
        cin>>b;
        factorial(b);
    }
    return 0;
}