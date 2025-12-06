#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 1};
    int n = 4;

    unordered_set<int> s;

    bool duplicateFound = false;

    for(int i = 0; i < n; i++){
        // if element already exists ? duplicate
        if(s.find(arr[i]) != s.end()){
            duplicateFound = true;
            break;
        }
        s.insert(arr[i]);
    }

    cout << (duplicateFound ? "true" : "false");
    return 0;
}

