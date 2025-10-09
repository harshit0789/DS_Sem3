#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        freq[c - 'a']++;
        q.push(c);

        while (!q.empty() && freq[q.front() - 'a'] > 1) 
            q.pop();

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
}

