#include <iostream>
using namespace std;

int main() {
    int q[100], n, f = -1, r = -1, ch, x;
    cin >> n;

    while (true) {
        cin >> ch;

        if (ch == 1) {
            cin >> x;
            if ((f == 0 && r == n - 1) || (r + 1) % n == f)
                cout << "full\n";
            else {
                if (f == -1) f = 0;
                r = (r + 1) % n;
                q[r] = x;
            }
        }

        else if (ch == 2) {
            if (f == -1) cout << "empty\n";
            else {
                cout << q[f] << "\n";
                if (f == r) f = r = -1;
                else f = (f + 1) % n;
            }
        }

        else if (ch == 3) {
            if (f == -1) cout << "empty\n";
            else cout << "not empty\n";
        }

        else if (ch == 4) {
            if ((f == 0 && r == n - 1) || (r + 1) % n == f)
                cout << "full\n";
            else
                cout << "not full\n";
        }

        else if (ch == 5) {
            if (f == -1) cout << "empty\n";
            else {
                int i = f;
                while (true) {
                    cout << q[i] << " ";
                    if (i == r) break;
                    i = (i + 1) % n;
                }
                cout << "\n";
            }
        }

        else if (ch == 6) {
            if (f == -1) cout << "empty\n";
            else cout << q[f] << "\n";
        }

        else if (ch == 7) break;
    }
}