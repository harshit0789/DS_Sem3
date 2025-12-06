#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d){ data = d; next = NULL; }
};

int main() {

    // Example list: 10 -> 20 -> 30 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    int target, val, choice;
    cout << "Enter value to insert: ";
    cin >> val;

    cout << "Enter node value (before/after which you want to insert): ";
    cin >> target;

    cout << "1. Insert BEFORE\n2. Insert AFTER\nYour choice: ";
    cin >> choice;

    // Insert before head
    if (choice == 1 && head->data == target) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Target value not found!";
            return 0;
        }

        Node* newNode = new Node(val);

        if (choice == 1) {        // BEFORE
            prev->next = newNode;
            newNode->next = temp;
        } 
        else {                    // AFTER
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    cout << "List after operation: ";
    Node* t = head;
    while (t) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL";
}

