#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d){ data = d; next = NULL; }
};

int main() {

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position: " << pos;
            return 0;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value not found!";
}


