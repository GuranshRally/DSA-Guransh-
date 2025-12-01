#include <iostream>
using namespace std;

int main() {
    int n, ch;
    cin >> ch >> n;

    if (ch == 1) {
        int k = n;
        int a[n], x;
        for (int i = 0; i < k; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << a[i] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }

    else if (ch == 2) {
        int k = 3*n - 2;
        int a[k];
        for (int i = 0; i < k; i++) cin >> a[i];
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i == j + 1 || i + 1 == j) {
                    cout << a[p++] << " ";
                } else cout << 0 << " ";
            }
            cout << endl;
        }
    }

    else if (ch == 3) {
        int k = n*(n+1)/2;
        int a[k];
        for (int i = 0; i < k; i++) cin >> a[i];
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) cout << a[p++] << " ";
            for (int j = i+1; j < n; j++) cout << 0 << " ";
            cout << endl;
        }
    }

    else if (ch == 4) {
        int k = n*(n+1)/2;
        int a[k];
        for (int i = 0; i < k; i++) cin >> a[i];
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) cout << 0 << " ";
            for (int j = i; j < n; j++) cout << a[p++] << " ";
            cout << endl;
        }
    }

    else if (ch == 5) {
        int k = n*(n+1)/2;
        int a[k];
        for (int i = 0; i < k; i++) cin >> a[i];
        int p = 0;
        for (int i = 0; i < n; i++) {
            int t = p;
            for (int j = 0; j <= i; j++) cout << a[p++] << " ";
            for (int j = i+1; j < n; j++) cout << a[t++] << " ";
            cout << endl;
        }
    }
}