#include <iostream>
using namespace std;

int mL(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != i + 1) return i + 1;
    }
    return n;
}

int missBin(int a[], int n) {
    int l = 0, r = n - 2;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == m + 1) l = m + 1;
        else r = m - 1;
    }
    return l + 1;
}

int main() {
    int a[] = {1, 2, 3, 5, 6, 7};
    int n = 7;

    cout << mL(a, n) << endl;
    cout << missBin(a, n) << endl;
}