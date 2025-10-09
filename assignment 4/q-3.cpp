#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even" << endl;
        return;
    }

    queue<int> firstHalf, secondHalf;

    for (int i = 0; i < n / 2; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrSize; ++i) q.push(arr[i]);

    interleave(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

