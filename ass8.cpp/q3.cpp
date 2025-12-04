#include <iostream>
using namespace std;

struct N {
    int v;
    N* l;
    N* r;
};

N* add(N* t, int x) {
    if (!t) {
        t = new N;
        t->v = x;
        t->l = t->r = NULL;
    } else if (x < t->v) t->l = add(t->l, x);
    else if (x > t->v) t->r = add(t->r, x);
    return t;
}

N* minNode(N* t) {
    while (t->l) t = t->l;
    return t;
}

N* del(N* t, int x) {
    if (!t) return t;
    if (x < t->v) t->l = del(t->l, x);
    else if (x > t->v) t->r = del(t->r, x);
    else {
        if (!t->l && !t->r) {
            delete t;
            return NULL;
        }
        else if (!t->l) {
            N* p = t->r;
            delete t;
            return p;
        }
        else if (!t->r) {
            N* p = t->l;
            delete t;
            return p;
        }
        else {
            N* p = minNode(t->r);
            t->v = p->v;
            t->r = del(t->r, p->v);
        }
    }
    return t;
}

int maxD(N* t) {
    if (!t) return 0;
    int a = maxD(t->l);
    int b = maxD(t->r);
    return 1 + (a > b ? a : b);
}

int minD(N* t) {
    if (!t) return 0;
    int a = minD(t->l);
    int b = minD(t->r);
    if (!t->l || !t->r) return 1 + a + b;
    return 1 + (a < b ? a : b);
}

int main() {
    int n, x;
    cin >> n;

    N* root = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = add(root, x);
    }

    int d;
    cin >> d;
    root = del(root, d);

    cout << maxD(root) << "\n";
    cout << minD(root) << "\n";
}