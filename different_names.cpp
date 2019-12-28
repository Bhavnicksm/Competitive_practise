#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
    string line, word;
    map<string, int> data;
    getline(cin,line); 
    // cout<<line; 
    stringstream X(line); 
    
     while(getline(X, word, ' ')){
         data[word]++;
        //  cout<<word<<endl;      
     }  

    auto it1=data.begin();
    int flag=0;
    for(int i=0;i<(int)data.size();i++){
        if(it1->second >1){
            cout<<it1->first<<" "<<it1->second<<endl;
            flag++;
        }
        it1++;
    }
    if(flag==0)cout<<"-1"<<endl;
	return 0;
}