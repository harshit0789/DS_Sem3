#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d){ data = d; next = NULL; }
};

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(60);
    head->next->next->next = new Node(80);

    int key;
    cout << "Enter value to delete: ";
    cin >> key;

    if (head == NULL) {
        cout << "List empty!";
        return 0;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node* temp = head;
        Node* prev = NULL;

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value not found!";
            return 0;
        }

        prev->next = temp->next;
        delete temp;
    }

    cout << "Updated list: ";
    Node* t = head;
    while (t) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL";
}


