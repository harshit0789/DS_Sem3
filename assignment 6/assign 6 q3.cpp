// Question 3: 
#include <iostream>
#include <vector>
using namespace std;


struct DNode { int data; DNode* prev; DNode* next; DNode(int v): data(v), prev(nullptr), next(nullptr) {} };


struct CNode { int data; CNode* next; CNode(int v): data(v), next(nullptr) {} };

int main() {
    
    cout << "Enter DLL elements (end with -1): ";
    vector<int> v1; int x;
    while (cin >> x && x != -1) v1.push_back(x);
    DNode* dHead = nullptr;
    DNode* dTail = nullptr;
    for (int val : v1) {
        DNode* n = new DNode(val);
        if (!dHead) dHead = dTail = n;
        else { dTail->next = n; n->prev = dTail; dTail = n; }
    }
    int countDLL = 0; for (DNode* t = dHead; t; t = t->next) countDLL++;
    cout << "DLL size: " << countDLL << "\n";

    
    cout << "Enter CLL elements (end with -1): ";
    vector<int> v2; 
    while (cin >> x && x != -1) v2.push_back(x);
    CNode* cHead = nullptr;
    CNode* cTail = nullptr;
    for (int val : v2) {
        CNode* n = new CNode(val);
        if (!cHead) { cHead = n; cTail = n; cTail->next = cHead; }
        else { cTail->next = n; cTail = n; cTail->next = cHead; }
    }
    int countCLL = 0;
    if (cHead) {
        CNode* t = cHead;
        do { countCLL++; t = t->next; } while (t != cHead);
    }
    cout << "CLL size: " << countCLL << "\n";
    return 0;
}

