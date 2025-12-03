#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int q[1000];
    for (int i = 0; i < n; i++) cin >> q[i];

    int h = n / 2;
    int a[1000], b[1000], k = 0;

    for (int i = 0; i < h; i++) a[i] = q[i];
    for (int i = h; i < n; i++) b[i - h] = q[i];

    for (int i = 0; i < h; i++) {
        q[k++] = a[i];
        q[k++] = b[i];
    }

    for (int i = 0; i < k; i++) cout << q[i] << " ";
}