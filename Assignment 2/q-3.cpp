#include<iostream> 
using namespace std; 
int main(){ 
    int arr[]={1,2,4,5,6,7,8,9}; 
    int missing=-1; 
    int n=sizeof(arr)/sizeof(arr[0]); 
    for(int i=0;i<n-1;i++){ 
        if(arr[i]+1!=arr[i+1]){ 
            missing=arr[i]+1; 
            break; 
        } 
    } 
    cout<<missing; 
} 
