#include <iostream>
using namespace std;
const int SIZE = 5;
int arr[SIZE];
int front= -1;
int rear= -1;

bool isEmpty(){
    if(front==-1) return true;
    else return false;}

bool isFull(){ 
    if((rear+1)%SIZE==front) return true;
else return false;
 }

void enqueue(int x){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
         return; 
        }
    if(isEmpty()) front = 0;
    rear=(rear+1)%SIZE;
    arr[rear]=x;
    cout<<x<<"enqueued"<<endl;
}

void dequeue(){
    if(isEmpty()){cout<<"Queue is Empty"<<endl;
         return;
         }
    cout<<arr[front]<<"dequeued"<<endl;
    if(front==rear) front=rear=-1;
    else front=(front+1)%SIZE;
}

void peek(){
    if(isEmpty()) cout<<"Queue Empty"<<endl;
    else cout<<"Front:"<<arr[front]<<endl;
}

void display() {
    if(isEmpty()){ 
        cout << "Queue Empty"<<endl; 
        return;
    }
    cout<<"Queue: ";
    int i=front;
    while(true){
        cout<<arr[i]<<" ";
        if(i==rear)break;
        i=(i+1)%SIZE;
    }
    cout<<endl;
}

int main(){
    int choice, val;
    do {
        cout<<endl<<"1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit"<<endl;
        cin >> choice;
        switch (choice){
            case 1:cout<<"Enter value:";cin>>val;enqueue(val); break;
            
            case 2:dequeue();break;
            
            case 3:peek();break;

            case 4:display();break;
        }
    } while (choice != 5);
}
