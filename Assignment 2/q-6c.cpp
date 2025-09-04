#include<iostream> 
using namespace std; 
int main(){ 
    int arr[2][2]={1,2,3,4}; 
    int brr[2][2]={1,2,3,4}; 
    int ans[2][2]={0}; 
    for(int i=0;i<2;i++){ 
        for(int j=0;j<2;j++){ 
            for(int k=0;k<2;k++){ 
                ans[i][j]+=arr[i][k]*brr[k][j];  
            } 
        } 
    } 
    for(int i=0;i<2;i++){ 
        for(int j=0;j<2;j++){ 
            cout<<ans[i][j]<<" "; 
        } 
        cout<<endl; 
    } 
} 
