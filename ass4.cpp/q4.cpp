#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;

    queue<char> q;
    int f[256] = {0};

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        f[c]++;
        q.push(c);

        while (!q.empty() && f[q.front()] > 1) q.pop();

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}