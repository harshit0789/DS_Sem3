//Assignment 1 Question 2

#include<iostream>
#include<queue>
using namespace std;
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
	{
        cout<<arr[i]<<" ";}}
        
int main()
{
    int arr[]={1,1,3,3,3,4,2,5,7,7};
    
    int n=sizeof(arr)/sizeof(arr[0]);
    

  cout<<"before:";
  display(arr,n);
  queue<int>st;
  for(int i=0;i<n;i++)
  {
    if(st.size()==0) st.push(arr[i]);
    
    else if(st.back()==arr[i]) continue;
    
    else st.push(arr[i]);
  }
  int i=0;
  while(st.size()!=0)
  {
    arr[i]=st.front();
    i++;
    st.pop();
	}

 cout<<endl<<"after:";
display(arr,i);
}

