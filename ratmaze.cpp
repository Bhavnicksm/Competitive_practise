#include<iostream>
using namespace std;

/*
    Rat Maze problem: To exit the rat maze. All possible solutions.
    Tags: Backtracking, reccursion
*/

bool check(int i, int j, int maze[][20],int sol[], int n){
    if(i>=0 && i<n && j>=0 && j<n && maze[i][j]==1 && sol[n*i+j]==0)return 1;
    else return 0;
}

void recursion(int i, int j, int maze[][20],int sol[], int n){
    if((i==(n-1)) && (j==(n-1))){
        for(int i=0;i<n*n;i++){
            cout<<sol[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    //check for each direction...
    if(check(i,j+1,maze,sol,n)){
        sol[n*i+j+1]=1;
        recursion(i,j+1,maze,sol,n);
        sol[n*i+j+1]=0;
    }

    if(check(i+1,j,maze,sol,n)){
        sol[n*(i+1)+j]=1;
        recursion(i+1,j,maze,sol,n);
        sol[n*(i+1)+j]=0;
    }
    if(check(i,j-1,maze,sol,n)){
        sol[n*i+j-1]=1;
        recursion(i,j-1,maze,sol,n);
        sol[n*i+j-1]=0;
    }
    if(check(i-1,j,maze,sol,n)){
        sol[n*(i-1)+j]=1;
        recursion(i-1,j,maze,sol,n);
        sol[n*(i-1)+j]=0;
    }
    return;
}

void ratInAMaze(int maze[][20], int n){
    int sol[n*n];
    for(int i=0;i<(n*n);i++){
        sol[i]=0;
    }
    sol[0]=1;
    
    recursion(0,0,maze,sol,n);
}


int main(){
  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}


