 #include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int ch, x;

    while (true) {
        cin >> ch;

        if (ch == 1) {
            cin >> x;
            int s = q.size();
            q.push(x);
            for (int i = 0; i < s; i++) {
                q.push(q.front());
                q.pop();
            }
        }

        else if (ch == 2) {
            if (q.empty()) cout << "empty\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        else if (ch == 3) {
            if (q.empty()) cout << "empty\n";
            else cout << q.front() << "\n";
        }

        else if (ch == 4) {
            if (q.empty()) cout << "empty\n";
            else {
                queue<int> t = q;
                while (!t.empty()) {
                    cout << t.front() << " ";
                    t.pop();
                }
                cout << "\n";
            }
        }

        else if (ch == 5) break;
    }
}