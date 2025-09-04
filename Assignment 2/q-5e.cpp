#include<iostream> 
using namespace std; 
int main(){ 
    int arr[3][3]={1,2,3,4,5,6,7,8,9}; 
    int transpose[3][3]; 
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){ 
            transpose[i][j]=arr[i][j]; 
        } 
    } 
    for(int i=0;i<3;i++){ 
        for(int j=0;j<i;j++){ 
            swap(arr[i][j],arr[j][i]); 
        } 
    } 
    bool flag=true; 
    for(int i=0;i<3;i++){ 
        for(int j=0;j<i;j++){ 
            if(transpose[i][j]!=arr[i][j]){ 
                flag=false; 
                break;  
            } 
        } 
    } 
    cout<<flag; 
} 
