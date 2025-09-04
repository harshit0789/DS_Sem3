// 2. Given a string, reverse it using STACK.
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s="DataStructure";
    stack<int>st;//expected output erutcurtSataD
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    s.clear();
    while(st.size()>0){
        s+=st.top();
    st.pop();
    }
    cout<<s;
}
