
// 1. Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i) push(),(ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().





#include <iostream>
using namespace std;
int top = -1;
bool isEmpty()
{
    return (top == -1);
}

bool isFull(int size)
{
    return (top == size - 1);
}

void push(int stack[], int size, int value)
{
    if (isFull(size))
        cout << "size is full" << value << endl;
    else
    {
        stack[++top] = value;
        cout << value << " pushed into stack." << endl;
    }
}

void pop(int stack[])
{
    if (isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << stack[top--] << "popped from stack." << endl;
}

void display(int stack[])
{
    if (isEmpty())
        cout << "Stack is empty." << endl;
    else
    {
        cout << "Stack elements:";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " " << endl;
        }
    }
}

void peek(int stack[])
{
    if (isEmpty())
        cout << "Stack is empty." << endl;
    else
        cout << "Topmost element:" << stack[top] << endl;
}

int main()
{
    int size;
    cout << "Enter size of stack:";
    cin >> size;

    int stack[size];
    int choice = 0, value;

    while (choice != 7)
    {
        cout << "Menu" << endl;
        cout << "1 Push" << endl;
        cout << "2 Pop" << endl;
        cout << "3 Check if Empty" << endl;
        cout << "4 Check if Full" << endl;
        cout << "5 Display Stack" << endl;
        cout << "6 Peek" << endl;
        cout << "7 Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value to push:";
            cin >> value;
            push(stack, size, value);
        }

        else if (choice == 2)
            pop(stack);

        else if (choice == 3)
        {
            if (isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
        }

        else if (choice == 4)
        {
            if (isFull(size))
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
        }

        else if (choice == 5)
            display(stack);

        else if (choice == 6)
            peek(stack);

        else if (choice == 7)
            cout << "Exiting program" << endl;

        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}
