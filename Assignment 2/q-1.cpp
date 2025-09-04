#include<iostream> 
using namespace std; 
int main(){ 
    int arr[10]={1,2,3,4,5,6,7,8,9,10}; 
    int target=7; 
    int lo=0; 
    int hi=9; 
    bool flag=false; 
    while(lo<=hi){ 
        int mid=(lo+hi)/2; 
        if(arr[mid]==target){ 
            flag=true; 
            break;
        } 
        else if(arr[mid]>target) hi=mid-1; 
        else lo=mid+1;
    } 
    cout<<flag; 
} 
