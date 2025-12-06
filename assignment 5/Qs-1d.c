#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d){ data = d; next = NULL; }
};

int main() {
    // Example list
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);

    if (head == NULL) {
        cout << "List is empty!";
        return 0;
    }

    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;

    cout << "Updated List: ";
    Node* t = head;
    while (t) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL";
}

