#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])min=j;
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    cout<<"Selection Sort: ";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    cout<<"Insertion Sort: ";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    cout<<"Bubble Sort: ";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)L[i]=a[l+i];
    for(int j=0;j<n2;j++)R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j])a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1)
      a[k++]=L[i++];
    while
      (j<n2)a[k++]=R[j++];
}

void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(int a[],int l,int r){
    int p=a[l];
    int i=l-1,j=r+1;
    while(true){
        do{i++;}while(a[i]<p);
        do{j--;}while(a[j]>p);
        if(i>=j)return j;
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}

void quickSort(int a[],int l,int r){
    if(l<r){
        int p=partition(a,l,r);
        quickSort(a,l,p);
        quickSort(a,p+1,r);
    }
}

int main(){
    int a[]={5,2,9,1,6};
    int n=5;
    int b1[5],b2[5],b3[5],b4[5],b5[5];
    for(int i=0;i<n;i++){
        b1[i]=a[i];
        b2[i]=a[i];
        b3[i]=a[i];
        b4[i]=a[i];
        b5[i]=a[i];
    }
    selectionSort(b1,n);
    insertionSort(b2,n);
    bubbleSort(b3,n);
    mergeSort(b4,0,n-1);
    cout<<"Merge Sort: ";
    for(int i=0;i<n;i++)cout<<b4[i]<<" ";
    cout<<endl;
    quickSort(b5,0,n-1);
    cout<<"Quick Sort: ";
    for(int i=0;i<n;i++)cout<<b5[i]<<" ";
    cout<<endl;
    return 0;
}
