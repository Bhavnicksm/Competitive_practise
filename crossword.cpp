#include<bits/stdc++.h>
#include<iostream>
using namespace std;


typedef vector<int> vi;
#define PB push_back
#define VOUT(p) for(auto x:p) cout<<x<<" "; 
typedef vector<string> vs;
/*
    Crossword: 10*10 crossword puzzle solving.
    Tags: Backtracing, Recursion, unresolved
*/
void search(vs a, char matrix[][10],int index,int &truebit);

bool acrosscheck(int i, int j, int index, vs a, char matrix[][10]){
    cout<<"\n across check: ";
    int length=0;
    while(matrix[i][j+length]!='+'){
        if(matrix[i][j+length]=='-' || matrix[i][j+length]==a[index][length])
        length++;
    }
    cout<<length<<"\n";
    if(length!= a[index].size())return 0;
    else return 1;
}

bool downcheck(int i, int j, int index, vs a, char matrix[][10]){
    cout<<"\n down check: ";
    int length=0;
    while(matrix[i+length][j]!='+'){
        if(matrix[i+length][j]=='-' || matrix[i+length][j]==a[index][length])
        length++;
    }
    cout<<length<<"\n";
    if(length!= a[index].size())return 0;
    else return 1;
}

void checker(int i, int j, int index, vs a, char matrix[][10], int &truebit){
    cout<<"\n check flag "<<i<<" "<<j<<"\n";
    if(acrosscheck(i,j,index,a,matrix)){
        cout<<"\n accross check successfull for "<<i<<" "<<j<<"\n";
        //puts the string, while making a bool arr
        int arr[a[index].size()];
        for(int l=0;l<a[index].size();l++){
            if(matrix[i+l][j]=='-'){
                matrix[i+l][j]==a[index][l];
                arr[l]=1;
            }
            else if(matrix[i+l][j]==a[index][l]){
                arr[l]=0;
                continue;
            }
        }

        for(int m=0;m<10;m++){
            for(int n=0;n<10;n++){
                cout<<matrix[m][n]<<" ";
            }
            cout<<"\n";
        } 
        //runs search again.
        search(a,matrix,index+1,truebit);
        // if over, return [truebit]
        if(truebit==1)return;
        else{
            for(int l=0;l<a[index].size();l++){
                if(arr[l] == 1){
                    matrix[i+l][j]='-';
                }
                else continue;
            }
        }
    }
    else if(downcheck(i,j,index,a,matrix)){

        cout<<"\n down check successfull for "<<i<<" "<<j<<"\n";
        //puts the string, while making a bool arr
        int arr[a[index].size()];
        for(int l=0;l<a[index].size();l++){
            if(matrix[i][j+l]=='-'){
                matrix[i][j+l]==a[index][l];
                arr[l]=1;
            }
            else if(matrix[i][j+l]==a[index][l]){
                arr[l]=0;
                continue;
            }
        }

        for(int m=0;m<10;m++){
            for(int n=0;n<10;n++){
                cout<<matrix[m][n]<<" ";
            }
            cout<<"\n";
        } 
        search(a,matrix,index+1,truebit);
        if(truebit==1)return;
        else{
            for(int l=0;l<a[index].size();l++){
                if(arr[l] == 1){
                    matrix[i][j+l]='-';
                }
                else continue;
            }
        }
    }
    else return;
}

void search(vs a, char matrix[][10],int index,int &truebit){
    cout<<"\n search flag"<<index<<"\n";
    if(index>= a.size()){
        truebit=1;
        return;
    }
    else for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(matrix[i][j]== '+')continue;
                else if(matrix[i][j]== '-' || a[index].find(matrix[i][j])!=a[index].npos){
                    cout<<"\n"<<i<<" "<<j<<"\n";
                    checker(i,j,index,a,matrix,truebit);
                    if(truebit)return;
                }
            }
        }
cout<<"error";
}

void crossword(vs a ,char matrix[][10]){
    int truebit=0;
    search(a,matrix,0,truebit); 
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }  
}

int main(){
    char matrix[10][10];
    vs a;
    string delimiter=";";
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>matrix[i][j];
        }
    }
	string s;
    getline(cin,s);
    int pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != s.npos) {
    token = s.substr(0, pos);
    a.PB(token);
    s.erase(0, pos + delimiter.size());
    }
    a.PB(s);
    crossword(a,matrix);
    return 0;
}


