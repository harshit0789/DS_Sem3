#include<iostream> 
using namespace std; 
int main(){ 
    string a="cbedafghsjkel"; 
    for(int i=0;i<a.size()-1;i++){ 
        for(int j=0;j<a.size()-1;j++){ 
            if(a[j]>a[j+1]) swap(a[j],a[j+1]); 
        } 
    } 
    cout<<a; 
} 
