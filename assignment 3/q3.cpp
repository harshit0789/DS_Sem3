// 3. Write a program that checks if an expression has balanced parentheses.


#include<iostream>
using namespace std;
bool check(string s){
if(s[0]==')' || s[s.size()-1]=='(') return false;
int count1=0,count2=0;
for(int i=0;i<s.size();i++){
    if(s[i]=='(') count1++;
    else count2++;
}
if(count1!=count2) return false;
else return true;
}
int main(){
     string s="()()()()))(()())))";
     bool flag=check(s); 
 cout<< flag;
}
