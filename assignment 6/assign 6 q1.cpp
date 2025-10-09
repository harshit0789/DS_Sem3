// Question 1: 
#include <iostream>
using namespace std;


struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v): data(v), prev(NULL), next(NULL) {}
};
DNode* dHead = NULL;

void insertDLLFirst(int val) {
    DNode* n = new DNode(val);
    if (!dHead) { dHead = n; return; }
    n->next = dHead; dHead->prev = n; dHead = n;
}
void insertDLLLast(int val) {
    DNode* n = new DNode(val);
    if (!dHead) { dHead = n; return; }
    DNode* t = dHead;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}
void insertDLLAfter(int key, int val) {
    DNode* t = dHead;
    while (t && t->data != key) t = t->next;
    if (!t) { cout << "Key not found\n"; return; }
    DNode* n = new DNode(val);
    n->next = t->next; n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}
void insertDLLBefore(int key, int val) {
    DNode* t = dHead;
    while (t && t->data != key) t = t->next;
    if (!t) { cout << "Key not found\n"; return; }
    DNode* n = new DNode(val);
    n->next = t; n->prev = t->prev;
    if (t->prev) t->prev->next = n;
    else dHead = n;
    t->prev = n;
}
void deleteDLLNode(int key) {
    DNode* t = dHead;
    while (t && t->data != key) t = t->next;
    if (!t) { cout << "Not found\n"; return; }
    if (t->prev) t->prev->next = t->next;
    else dHead = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}
bool searchDLL(int key) {
    for (DNode* t = dHead; t; t = t->next) if (t->data == key) return true;
    return false;
}
void displayDLL() {
    if (!dHead) { cout << "Empty\n"; return; }
    for (DNode* t = dHead; t; t = t->next) cout << t->data << " ";
    cout << "\n";
}
int sizeDLL() {
    int c = 0;
    for (DNode* t = dHead; t; t = t->next) c++;
    return c;
}


struct CNode {
    int data;
    CNode* next;
    CNode(int v): data(v), next(NULL) {}
};
CNode* cHead = NULL;

void insertCLLFirst(int val) {
    CNode* n = new CNode(val);
    if (!cHead) { cHead = n; n->next = cHead; return; }
    CNode* tail = cHead;
    while (tail->next != cHead) tail = tail->next;
    n->next = cHead; tail->next = n; cHead = n;
}
void insertCLLLast(int val) {
    CNode* n = new CNode(val);
    if (!cHead) { cHead = n; n->next = cHead; return; }
    CNode* tail = cHead;
    while (tail->next != cHead) tail = tail->next;
    tail->next = n; n->next = cHead;
}
void insertCLLAfter(int key, int val) {
    if (!cHead) { cout << "Empty\n"; return; }
    CNode* t = cHead;
    do {
        if (t->data == key) { CNode* n = new CNode(val); n->next = t->next; t->next = n; return; }
        t = t->next;
    } while (t != cHead);
    cout << "Key not found\n";
}
void insertCLLBefore(int key, int val) {
    if (!cHead) { cout << "Empty\n"; return; }
    CNode* t = cHead;
    CNode* prev = NULL;
    do {
        if (t->data == key) break;
        prev = t;
        t = t->next;
    } while (t != cHead);
    if (t->data != key) { cout << "Key not found\n"; return; }
    CNode* n = new CNode(val);
    if (t == cHead) {
        
        CNode* tail = cHead;
        while (tail->next != cHead) tail = tail->next;
        n->next = cHead; tail->next = n; cHead = n;
    } else {
        prev->next = n; n->next = t;
    }
}
void deleteCLLNode(int key) {
    if (!cHead) { cout << "Empty\n"; return; }
    CNode* cur = cHead; CNode* prev = NULL;
    do {
        if (cur->data == key) break;
        prev = cur; cur = cur->next;
    } while (cur != cHead);
    if (cur->data != key) { cout << "Not found\n"; return; }
    if (cur == cHead) {
        if (cHead->next == cHead) { delete cHead; cHead = NULL; return; }
        CNode* tail = cHead;
        while (tail->next != cHead) tail = tail->next;
        tail->next = cHead->next;
        CNode* toDel = cHead; cHead = cHead->next; delete toDel;
    } else {
        prev->next = cur->next; delete cur;
    }
}
bool searchCLL(int key) {
    if (!cHead) return false;
    CNode* t = cHead;
    do {
        if (t->data == key) return true;
        t = t->next;
    } while (t != cHead);
    return false;
}
void displayCLL() {
    if (!cHead) { cout << "Empty\n"; return; }
    CNode* t = cHead;
    do { cout << t->data << " "; t = t->next; } while (t != cHead);
    cout << "\n";
}

void displayCLLRepeatHead() {
    if (!cHead) { cout << "Empty\n"; return; }
    CNode* t = cHead;
    do { cout << t->data << " "; t = t->next; } while (t != cHead);
    cout << cHead->data << "\n";
}
int sizeCLL() {
    if (!cHead) return 0;
    int c = 0; CNode* t = cHead;
    do { c++; t = t->next; } while (t != cHead);
    return c;
}


int main() {
    while (true) {
        cout << "\n--- Choose List Type ---\n1. Doubly Linked List (DLL)\n2. Circular Linked List (CLL)\n0. Exit\nChoice: ";
        int lt;
        if (!(cin >> lt)) { cout << "Invalid input. Exiting.\n"; return 0; }
        if (lt == 0) break;

        if (lt == 1) {
            while (true) {
                cout << "\nDLL Menu:\n1.Insert First  2.Insert Last  3.Insert After  4.Insert Before\n"
                     << "5.Delete Node  6.Search  7.Display  8.Size  0.Back\nChoice: ";
                int op; cin >> op;
                if (op == 0) break;
                if (op == 1) { int v; cout<<"Value: "; cin>>v; insertDLLFirst(v); }
                else if (op == 2) { int v; cout<<"Value: "; cin>>v; insertDLLLast(v); }
                else if (op == 3) { int k,v; cout<<"Key After: "; cin>>k; cout<<"Value: "; cin>>v; insertDLLAfter(k,v); }
                else if (op == 4) { int k,v; cout<<"Key Before: "; cin>>k; cout<<"Value: "; cin>>v; insertDLLBefore(k,v); }
                else if (op == 5) { int k; cout<<"Delete Value: "; cin>>k; deleteDLLNode(k); }
                else if (op == 6) { int k; cout<<"Search Value: "; cin>>k; cout<<(searchDLL(k) ? "Found\n":"Not Found\n"); }
                else if (op == 7) displayDLL();
                else if (op == 8) cout<<"Size: "<<sizeDLL()<<"\n";
                else cout<<"Invalid\n";
            }
        } else if (lt == 2) {
            while (true) {
                cout << "\nCLL Menu:\n1.Insert First  2.Insert Last  3.Insert After  4.Insert Before\n"
                     << "5.Delete Node  6.Search  7.Display  8.Display (repeat head)  9.Size  0.Back\nChoice: ";
                int op; cin >> op;
                if (op == 0) break;
                if (op == 1) { int v; cout<<"Value: "; cin>>v; insertCLLFirst(v); }
                else if (op == 2) { int v; cout<<"Value: "; cin>>v; insertCLLLast(v); }
                else if (op == 3) { int k,v; cout<<"Key After: "; cin>>k; cout<<"Value: "; cin>>v; insertCLLAfter(k,v); }
                else if (op == 4) { int k,v; cout<<"Key Before: "; cin>>k; cout<<"Value: "; cin>>v; insertCLLBefore(k,v); }
                else if (op == 5) { int k; cout<<"Delete Value: "; cin>>k; deleteCLLNode(k); }
                else if (op == 6) { int k; cout<<"Search Value: "; cin>>k; cout<<(searchCLL(k) ? "Found\n":"Not Found\n"); }
                else if (op == 7) displayCLL();
                else if (op == 8) displayCLLRepeatHead();
                else if (op == 9) cout<<"Size: "<<sizeCLL()<<"\n";
                else cout<<"Invalid\n";
            }
        } else cout << "Invalid list type\n";
    }
    cout << "Program ended.\n";
    return 0;
}


