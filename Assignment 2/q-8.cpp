#include<iostream> 
#include<set> 
using namespace std; 
int main(){ 
    set<int>a; 
    int arr[10]={1,1,1,3,2,4,3,2,4,5}; 
    for(auto x:arr){ 
        a.insert(x); 
    } 
    cout<<a.size(); 
} 
