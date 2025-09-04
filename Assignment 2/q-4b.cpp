#include<iostream> 
using namespace std; 
int main(){ 
    string a="abcde"; 
    int i=0; 
    int j=a.size()-1; 
    while(i<j){ 
        swap(a[i],a[j]); 
        i++; 
        j--; 
    }  
    cout<<a; 
} 
