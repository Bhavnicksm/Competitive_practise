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
   The Lead game;
*/

int main(){
    int n, p1=0,p2=0,ml=0,mp=0;
    cin>>n;
    for(int i=0;i<2*n;i+=2){
        int s1,s2;
        int cl,cp;
        cin>>s1>>s2;
        p1+=s1;
        p2+=s2;
        if(p1>=p2){
            cl=p1-p2;
            cp=1;
        }
        else{
            cl=p2-p1;
            cp=2;
        }
        if(cl>ml){
            ml=cl;
            mp=cp;
        }
    }
    cout<<mp<<" "<<ml<<endl;
    return 0;
}