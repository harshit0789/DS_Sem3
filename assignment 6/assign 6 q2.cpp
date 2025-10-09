// Question 2:
#include <iostream>
#include <vector>
using namespace std;

struct CNode { int data; CNode* next; CNode(int v): data(v), next(nullptr) {} };

int main() {
    cout << "Enter integers for CLL (end with -1): ";
    vector<int> a;
    int x;
    while (cin >> x && x != -1) a.push_back(x);
    if (a.empty()) { cout << "Empty\n"; return 0; }

   
    CNode* head = new CNode(a[0]);
    head->next = head;
    CNode* tail = head;
    for (size_t i = 1; i < a.size(); ++i) {
        CNode* n = new CNode(a[i]);
        tail->next = n; n->next = head; tail = n;
    }

    
    CNode* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << "\n"; 
    return 0;
}
