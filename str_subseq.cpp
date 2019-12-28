#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
   String Subsequences: Print out all the string subsequences. 
   Tags: Recursion, strings
*/

int subsequence(string in, string out[]){
    if(in.empty()){
        out[0]="";
        return 1;
    }

    int size=subsequence(in.substr(1),out);
    for(int  i=0;i<size;i++){
        out[i+size]=in[0]+out[i];
    }
    return (2*size);
}

int main(){
    string in;
    cin>>in;
    int size=pow(2,in.size());
    string *out= new string[size];
    size = subsequence(in, out);
    for(int i=0;i<size;i++){
        cout<<out[i]<<endl;
    }
    delete[] out;
    return 0;
}