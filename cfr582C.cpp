#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;


#define REP(i,a,b) for(int i=a;i<b;i++)
#define PB push_back
#define MP make_pair

/*
   Finding the sum of the last digits of the numbers from 1-n divisble by m.
*/
int main(){
   int q;
   cin>>q;
   vector<ull> p;
   REP(i,0,q){
       ull n,m,sum=0,digits=0;
       cin>>n>>m;
       for(ull j=1;j<=10;j++){
           digits=digits+((j*m)%10);
       }
    //    cout<<digits<<endl;
       ull x=n%(m*10);
    //    cout<<x<<endl;
       for(ull j=0;j<=x;j+=m){
           sum=sum+(j%10);
       }
    //    cout<<sum<<endl;
       ull y= ((n/(m*10))*digits)+sum;
    //    cout<<y<<endl;
       p.PB(y);
   }
   REP(i,0,q){
       cout<<p[i]<<endl;
   }
}