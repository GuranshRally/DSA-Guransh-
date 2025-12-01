#include <iostream>
using namespace std;

struct T {
    int r, c, v;
};

void trans(T a[], T b[]) {
    int k = a[0].v;
    b[0].r = a[0].c;
    b[0].c = a[0].r;
    b[0].v = k;

    int p = 1;
    for (int i = 0; i < a[0].c; i++) {
        for (int j = 1; j <= k; j++) {
            if (a[j].c == i) {
                b[p].r = a[j].c;
                b[p].c = a[j].r;
                b[p].v = a[j].v;
                p++;
            }
        }
    }
}

void add(T a[], T b[], T c[]) {
    if (a[0].r != b[0].r || a[0].c != b[0].c) return;
    int i = 1, j = 1, p = 1;
    int n1 = a[0].v, n2 = b[0].v;

    c[0].r = a[0].r;
    c[0].c = a[0].c;

    while (i <= n1 && j <= n2) {
        if (a[i].r < b[j].r || (a[i].r == b[j].r && a[i].c < b[j].c)) {
            c[p++] = a[i++];
        } else if (b[j].r < a[i].r || (b[j].r == a[i].r && b[j].c < a[i].c)) {
            c[p++] = b[j++];
        } else {
            int x = a[i].v + b[j].v;
            if (x != 0) {
                c[p].r = a[i].r;
                c[p].c = a[i].c;
                c[p].v = x;
                p++;
            }
            i++;
            j++;
        }
    }
    while (i <= n1) c[p++] = a[i++];
    while (j <= n2) c[p++] = b[j++];

    c[0].v = p - 1;
}

void mul(T a[], T b[], T c[]) {
    if (a[0].c != b[0].r) return;

    T bt[100];
    trans(b, bt);

    int p = 1;
    c[0].r = a[0].r;
    c[0].c = b[0].c;

    for (int i = 1; i <= a[0].v; i++) {
        for (int j = 1; j <= bt[0].v; j++) {
            if (a[i].c == bt[j].c) {
                int rr = a[i].r;
                int cc = bt[j].r;
                int val = a[i].v * bt[j].v;

                int f = 0;
                for (int k = 1; k < p; k++) {
                    if (c[k].r == rr && c[k].c == cc) {
                        c[k].v += val;
                        f = 1;
                        break;
                    }
                }

                if (!f && val != 0) {
                    c[p].r = rr;
                    c[p].c = cc;
                    c[p].v = val;
                    p++;
                }
            }
        }
    }

    c[0].v = p - 1;
}

void print(T a[]) {
    for (int i = 0; i <= a[0].v; i++)
        cout << a[i].r << " " << a[i].c << " " << a[i].v << endl;
}

int main() {
    int n1, n2;
    T a[100], b[100], t[100], d[100], m[100];

    cin >> n1;
    for (int i = 0; i < n1; i++)
        cin >> a[i].r >> a[i].c >> a[i].v;

    cin >> n2;
    for (int i = 0; i < n2; i++)
        cin >> b[i].r >> b[i].c >> b[i].v;

    trans(a, t);
    add(a, b, d);
    mul(a, b, m);

    print(t);
    cout << endl;
    print(d);
    cout << endl;
    print(m);
}