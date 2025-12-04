#include <iostream>
using namespace std;

void sel(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[k]) k = j;
        int t = a[i];
        a[i] = a[k];
        a[k] = t;
    }
}

void ins(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void bub(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

void mergeArr(int a[], int l, int m, int r) {
    int x = m - l + 1, y = r - m;
    int L[500], R[500];
    for (int i = 0; i < x; i++) L[i] = a[l + i];
    for (int i = 0; i < y; i++) R[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < x && j < y) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < x) a[k++] = L[i++];
    while (j < y) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeArr(a, l, m, r);
    }
}

int part(int a[], int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] < p) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = part(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int n, a[1000], ch;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> ch;

    if (ch == 1) sel(a, n);
    else if (ch == 2) ins(a, n);
    else if (ch == 3) bub(a, n);
    else if (ch == 4) mergeSort(a, 0, n - 1);
    else if (ch == 5) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}