#include<iostream> 
using namespace std; 
int main(){ 
    string a="AJSCNDKSLSJFOF"; 
    for(int i=0;i<a.size();i++){ 
        a[i]+=32; 
    } 
    cout<<a; 
} 
