#include<iostream>
using namespace std;

int main(){
    int a[]={4,2,8,1,6,3};
    int n=6;
    int start=0,end=n-1;
    while(start<end){
        int min=start,max=start;
        for(int i=start;i<=end;i++){
            if(a[i]<a[min])min=i;
            if(a[i]>a[max])max=i;
        }
        int t=a[start];
        a[start]=a[min];
        a[min]=t;
        if(max==start)max=min;
        t=a[end];
        a[end]=a[max];
        a[max]=t;
        start++;
        end--;
    }
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
