#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
   Sudoku: Solving a given sudoku puzzle one zero at a time.
   tags: backtracking, recursion
*/

bool check(int k, int i, int j, int matrix[][9]){
    //check row
    for(int l=0;l<9;l++){
        if(matrix[i][l]==k)return 0;
    }
    //check column
    for(int l=0;l<9;l++){
        if(matrix[l][j]==k)return 0;
    }
    //check box
    int si=((i/3)*3),fi=(((i/3)+1)*3);
    int sj=((j/3)*3),fj=(((j/3)+1)*3);
    for(int l=si;l<fi;l++){
        for(int m=sj;m<fj;m++){
            if(matrix[l][m]==k)return 0;
        }
    }

    return 1;
}


void recursion(int i, int j, int matrix[][9], int & flag);

void search(int i, int j, int matrix[][9],int & flag){
    for(int l=0;l<9;l++){
        for(int m=0;m<9;m++){
            if(matrix[l][m]==0){
                recursion(l,m,matrix,flag);
                return;
            }
        }
    }
    flag=1;
    return;
}

void recursion(int i, int j, int matrix[][9], int &flag){
    for(int k=1;k<10;k++){
        if(check(k,i,j,matrix)){
            matrix[i][j]=k;
            search(i,j,matrix,flag);
            if(flag==1)return;
            matrix[i][j]=0;
        }
    }
    return;
}

void sudoku(int matrix[][9]){
    int flag=0;
    search(0,0,matrix,flag);
    cout<<"\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int mx[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>mx[i][j];
        }
    }
    sudoku(mx);
    return 0;
}