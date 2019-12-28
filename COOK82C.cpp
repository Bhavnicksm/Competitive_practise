#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//General functionality help
typedef long long ll;
#define REP(i,a,b) for(int i=a;i<b;i++)

//Vector functionality help
typedef vector<int> vi;
#define PB push_back
#define VOUT(p) for(auto x:p) cout<x<<" "; 

/*
   #2
   COOK82C: Asks to maintain a multiset, delete the max number and insert half of it.
   Method: Queue implementation
   Result: TLE
*/

// void showq(queue <ll> gq) 
// { 
//     queue <ll> g = gq; 
//     while (!g.empty()) 
//     { 
//         cout << '\t' << g.front(); 
//         g.pop(); 
//     } 
//     cout << '\n'; 
// }

int main(){
    multiset<ll> arr;
    int m,n;
    cin>>n>>m;
    vi Q(m);
    queue<ll> b;

    REP(i,0,n){
        ll x; cin>>x;
        arr.insert(x);
    }

    REP(i,0,m){
        ll x; cin>>x;
        Q[i]=x;
    }
    int maxQ=*max_element(Q.begin(),Q.end());
    int k=0;
    for(int i=1;i<=maxQ;i++){
        ll last;
        auto it=arr.end();
        if(!arr.empty()){ 
            it--;
            last=*it;
        }
        else last=0;

        ll maxi;
        if((!b.empty()) && b.front()>last){
            maxi=b.front();
            b.pop();
        }
        else{
            maxi=last;
            arr.erase(it);
        }
        if(Q[k]==i){
            cout<<maxi<<endl;
            k++;
        }
        maxi/=2;
        if(maxi>0){
            b.push(maxi);
        }
        // cout<<endl;
        // for(auto x:arr){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // showq(b);
        // cout<<endl;
    }
    return 0;
}


/*
   COOK82C: Asks to maintain a multiset, delete the max number and insert half of it.
   Method: Naive approach
   Result: Time limit exceeded.
*/
/*
int main(){
    multiset<ll> arr;
    int m,n;
    cin>>n>>m;
    vi Q(m);
    
    REP(i,0,n){
        ll x; cin>>x;
        arr.insert(x);
    }

    REP(i,0,m){
        ll x; cin>>x;
        Q[i]=x;
    }
    int maxQ=*max_element(Q.begin(),Q.end());
    int k=0;
    for(int i=1;i<=maxQ;i++){
        auto it=arr.end(); it--;
        ll x= *it;
        if(Q[k]==i){
            cout<<x<<endl;
            k++;
        }
        arr.erase(it);
        x/=2;
        if(x>0){
            arr.insert(x);
        }
    }
    return 0;
}
*/