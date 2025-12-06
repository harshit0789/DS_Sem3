#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

int main() {

    Node* head = NULL;

    int val;
    cout << "Enter value to insert at end: ";
    cin >> val;

    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Inserted at end. Final list: " << head->data << " -> NULL";
}


