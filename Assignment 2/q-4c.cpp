#include<iostream> 
using namespace std; 
bool vowel(char c){ 
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
} 
int main(){ 
    string a="aevuisofdbc"; 
    string ans=""; 
    for(int i=0;i<a.size();i++){ 
        if(!vowel(a[i])) ans+=a[i]; 
    } 
    cout<<ans; 
} 
