#include<iostream>
using namespace std;

int partition(int input[],int size){
    int a=input[0],small=0;
    for(int i=1;i<size;i++){
        if(input[i] <= a){
            small++;
        }
    }
    for(int i=0;i<small;i++){
        input[i]=input[i+1];
    }
    input[small]=a;
    
    for(int i=0,j=size-1;i<small && j>small;){
        if(input[i]<=a){
            i++;
        }
        else if(input[j]>a){
            j--;
        }
        else{
            int t=input[i];
            input[i]=input[j];
            input[j]=t;
        }
    }
    return small;
}

void quickSort(int input[], int size) {
    if(size <= 1)return;
    
    int a=partition(input,size);
    quickSort(input,a);
    quickSort(input+a+1,size-a-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


