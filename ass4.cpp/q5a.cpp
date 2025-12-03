#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;
    int ch, x;

    while (true) {
        cin >> ch;

        if (ch == 1) {
            cin >> x;
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1, q2);
        }

        else if (ch == 2) {
            if (q1.empty()) cout << "empty\n";
            else {
                cout << q1.front() << "\n";
                q1.pop();
            }
        }

        else if (ch == 3) {
            if (q1.empty()) cout << "empty\n";
            else cout << q1.front() << "\n";
        }

        else if (ch == 4) {
            if (q1.empty()) cout << "empty\n";
            else {
                queue<int> t = q1;
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