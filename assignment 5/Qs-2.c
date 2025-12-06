#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

int main() {

    // Creating the sample list: 1->2->1->2->1->3->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    int key = 1;
    int count = 0;

    // Step 1: Remove all occurrences at the start
    while (head != NULL && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        count++;
    }

    // If list becomes empty
    if (head == NULL) {
        cout << "Count: " << count << "\nUpdated List: (empty)";
        return 0;
    }

    // Step 2: Remove from remaining list
    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;

    cout << "Updated Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}


