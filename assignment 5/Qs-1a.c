#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// insert at front
void push_front(Node*& head, int data) {
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void freeList(Node*& head) {
    Node* cur = head;
    while(cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;

    push_front(head, 30);
    push_front(head, 20);
    push_front(head, 10);

    cout << "After push_front calls:\n";
    printList(head);

    freeList(head);

    return 0;
}

