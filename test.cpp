#include <iostream>
#include <string>
using namespace std;

void keypad(int num, string out){
     string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     int select=num%10;
     if(num==0){
         cout<<out<<endl;
     }
     for(int i=0;i<key[select].size();i++){
         keypad(num/10,key[select][i]+out);
     }
}

void printKeypad(int num){
    string out="";
    keypad(num,out);
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
