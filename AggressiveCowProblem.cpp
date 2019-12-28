#include<bits/stdc++.h>
using namespace std;

/*
  Aggressive Cow Problem: Checking the largest minimum between c different numbers.
*/

//General functionality help
typedef long long ll;
#define REP(i,a,b) for(int i=a;i<b;i++)

//Vector functionality help
typedef vector<int> vi;
#define PB push_back
#define VOUT(p) for(auto x:p) cout<<x<<" "; 

bool checker(vi arr,int n,int c,int d){
    int c_check=0;
//    cout<<"checker: ";

    int curr=arr[0];
    for(int i=0;i<n;i++){
        int next=curr+d;
        if(arr[i]>=next){
            curr=arr[i];
            // cout<<curr<<" ";
            c_check++;
        }
        if(c_check==c-1){
            // cout<<"\n";
            return true;
        }
    }
    return false;
}

int main() {
    // Basic code requirements
    int t,n,c,d;
    cin>>t;
    while(t--){
        cin>>n>>c;    
        vi arr(n);
        REP(i,0,n)cin>>arr[i];
        sort(arr.begin(),arr.end());
        //establishing the difference arr
        vi diff(n);
        REP(i,0,n)diff[i]=arr[n-1]-arr[i];
        int max=*max_element(diff.begin(),diff.end());
        d=max/2;
        int begin=0,end=max;
        //test case loop
        while(begin<=end){
            // cout<<"\n"<<d<<" "<<begin<<" "<<end<<"\n\n";
            if(checker(arr,n,c,d)){
                begin=d+1;
                d=(end+begin)/2;
            }
            else{
                end=d-1;
                d=(end+begin)/2;
            }
        }
    cout<<d<<"\n";
    }
    return 0;  
}