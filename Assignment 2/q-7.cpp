#include<iostream> 
using namespace std; 
int main(){ 
    int arr[10]={1,2,3,4,5,4,3,2,1,10}; 
    int pair=0; 
    for(int i=0;i<9;i++){ 
        for(int j=i+1;j<10;j++){ 
            if(i<j && arr[i]>arr[j]) pair++; 
        } 
    } 
    cout<<pair; 
} 
