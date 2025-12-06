#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

bool checkDuplicates(Node* root, unordered_set<int>& s){
    if(!root) return false;

    if(s.count(root->val)) return true;
    s.insert(root->val);

    return checkDuplicates(root->left, s) || checkDuplicates(root->right, s);
}

int main(){
    unordered_set<int> s;

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(20); // duplicate

    cout << (checkDuplicates(root, s) ? "Duplicates Found" : "No Duplicates");

    return 0;
}

