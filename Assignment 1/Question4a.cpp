//Assignment 1 Question 4a


#include<iostream>
using namespace std;
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";}}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"before reversing:";
    display(arr,10);
    
    
    int i=0;
    int j=9;
    while(i<j){
swap(arr[i],arr[j]);//swapping 

i++;
j--;
    }
    cout<<endl<<"after reversing:";
    display(arr,10);
	}
    



