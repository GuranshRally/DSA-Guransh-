#include <iostream>
using namespace std;

int main() {
    int q[100], n, f = 0, r = -1, ch, x;
    cin >> n;

    while (true) {
        cin >> ch;

        if (ch == 1) {
            if (r == n - 1) cout << "full\n";
            else {
                cin >> x;
                r++;
                q[r] = x;
            }
        }

        else if (ch == 2) {
            if (f > r) cout << "empty\n";
            else {
                cout << q[f] << "\n";
                f++;
            }
        }

        else if (ch == 3) {
            if (f > r) cout << "empty\n";
            else cout << "not empty\n";
        }

        else if (ch == 4) {
            if (r == n - 1) cout << "full\n";
            else cout << "not full\n";
        }

        else if (ch == 5) {
            if (f > r) cout << "empty\n";
            else {
                for (int i = f; i <= r; i++) cout << q[i] << " ";
                cout << "\n";
            }
        }

        else if (ch == 6) {
            if (f > r) cout << "empty\n";
            else cout << q[f] << "\n";
        }

        else if (ch == 7) break;
    }
}