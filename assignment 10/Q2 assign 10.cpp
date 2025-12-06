#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n1 = 4, n2 = 4;

    unordered_set<int> setA;
    for(int x : A) setA.insert(x);

    cout << "Common Elements: ";

    for(int y : B){
        if(setA.count(y)) {
            cout << y << " ";
        }
    }

    return 0;
}

