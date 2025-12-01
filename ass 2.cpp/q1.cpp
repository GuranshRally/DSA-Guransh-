#include <iostream>
using namespace std;

int bsearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int lsearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int nums[] = {2, 5, 8, 12, 18, 21};
    int n = 6;
    int val = 12;

    cout << bsearch(nums, n, val) << endl;
    cout << lsearch(nums, n, val) << endl;
}