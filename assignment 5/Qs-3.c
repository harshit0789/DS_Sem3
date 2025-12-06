#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) { data = d; next = NULL; }
};

int main() {

    // Example list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* slow = head;
    Node* fast = head;

    // fast moves 2 steps, slow moves 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data;

    return 0;
}


