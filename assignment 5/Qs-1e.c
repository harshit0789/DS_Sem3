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
    head->next->next = new Node(30);

    if (head == NULL) {
        cout << "List empty!";
        return 0;
    }

    if (head->next == NULL) {
        cout << "Deleted: " << head->data;
        delete head;
        head = NULL;
        return 0;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    cout << "Deleted: " << temp->data << endl;
    prev->next = NULL;
    delete temp;

    cout << "Updated List: ";
    Node* t = head;
    while (t) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL";
}


