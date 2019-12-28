#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
  ATM problem from beginner section from codechef; HS08TEST
*/


int main(){
    int withdraw;
    float balance;
    scanf("%d %f",&withdraw,&balance);
    if((withdraw%5==0)&&(balance>=withdraw+0.5)){
        cout<<balance-(withdraw+0.5)<<"\n";
    }
    else cout<<balance<<"\n";
    return 0;
}