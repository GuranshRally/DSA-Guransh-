#include <iostream>
#include <climits>
using namespace std;

int h[1000];
int sz = 0;
int mode = 1;

void swapv(int &a, int &b) { int t = a; a = b; b = t; }

void heapUpMax(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[i] > h[p]) swapv(h[i], h[p]), i = p;
        else break;
    }
}

void heapDownMax(int i, int n) {
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int mx = i;
        if (l < n && h[l] > h[mx]) mx = l;
        if (r < n && h[r] > h[mx]) mx = r;
        if (mx != i) swapv(h[i], h[mx]), i = mx;
        else break;
    }
}

void heapUpMin(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[i] < h[p]) swapv(h[i], h[p]), i = p;
        else break;
    }
}

void heapDownMin(int i, int n) {
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int mn = i;
        if (l < n && h[l] < h[mn]) mn = l;
        if (r < n && h[r] < h[mn]) mn = r;
        if (mn != i) swapv(h[i], h[mn]), i = mn;
        else break;
    }
}

void insert(int x) {
    h[sz] = x;
    if (mode == 1) heapUpMax(sz);
    else heapUpMin(sz);
    sz++;
}

int extract() {
    if (sz == 0) return INT_MIN;
    int res = h[0];
    h[0] = h[sz-1];
    sz--;
    if (mode == 1) heapDownMax(0, sz);
    else heapDownMin(0, sz);
    return res;
}

int peekv() {
    if (sz == 0) return INT_MIN;
    return h[0];
}

bool emptyq() { return sz == 0; }
int sizeq() { return sz; }

void buildFromArray(int a[], int n) {
    for (int i = 0; i < n; i++) h[i] = a[i];
    sz = n;
    for (int i = (sz/2)-1; i >= 0; i--) {
        if (mode == 1) heapDownMax(i, sz);
        else heapDownMin(i, sz);
    }
}

void show() {
    for (int i = 0; i < sz; i++) cout << h[i] << " ";
    cout << "\n";
}

int main() {
    int choice, x;
    cin >> mode;
    while (true) {
        cin >> choice;
        if (choice == 1) {
            cin >> x;
            insert(x);
        } else if (choice == 2) {
            int v = extract();
            if (v == INT_MIN) cout << "empty\n"; else cout << v << "\n";
        } else if (choice == 3) {
            int v = peekv();
            if (v == INT_MIN) cout << "empty\n"; else cout << v << "\n";
        } else if (choice == 4) {
            if (emptyq()) cout << "empty\n"; else cout << "not empty\n";
        } else if (choice == 5) {
            cout << sizeq() << "\n";
        } else if (choice == 6) {
            show();
        } else if (choice == 7) {
            int n;
            cin >> n;
            int a[500];
            for (int i = 0; i < n; i++) cin >> a[i];
            buildFromArray(a, n);
        } else if (choice == 8) break;
    }
}