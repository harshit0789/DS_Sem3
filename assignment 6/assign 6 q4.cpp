// Question 4: 
#include <iostream>
#include <string>
using namespace std;

struct Node { char ch; Node* prev; Node* next; Node(char c): ch(c), prev(nullptr), next(nullptr) {} };

int main() {
    cout << "Enter string (no spaces): ";
    string s; cin >> s;
    if (s.empty()) { cout << "True\n"; return 0; }

    
    Node* head = nullptr;
    Node* tail = nullptr;
    for (char c : s) {
        Node* n = new Node(c);
        if (!head) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
    }

    
    Node* l = head; Node* r = tail;
    bool ok = true;
    while (l && r && l != r && l->prev != r) {
        if (l->ch != r->ch) { ok = false; break; }
        l = l->next; r = r->prev;
    }
    cout << (ok ? "True\n" : "False\n");
    return 0;
}

