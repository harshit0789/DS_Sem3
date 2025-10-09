// Question 5: 
#include <iostream>
#include <vector>
using namespace std;

struct Node { int data; Node* next; Node(int v): data(v), next(nullptr) {} };

bool isCircular(Node* head) {
    if (!head) return false;
    Node* t = head->next;
    while (t && t != head) t = t->next;
    return t == head;
}

int main() {
    cout << "Enter list elements (end with -1): ";
    vector<int> a; int x;
    while (cin >> x && x != -1) a.push_back(x);
    if (a.empty()) { cout << "False\n"; return 0; }

    Node* head = new Node(a[0]);
    Node* tail = head;
    for (size_t i = 1; i < a.size(); ++i) {
        tail->next = new Node(a[i]);
        tail = tail->next;
    }

    cout << "Make list circular? (1 = yes, 0 = no): ";
    int choice; cin >> choice;
    if (choice == 1) tail->next = head;
    else tail->next = nullptr;

    cout << (isCircular(head) ? "True\n" : "False\n");
    return 0;
}

