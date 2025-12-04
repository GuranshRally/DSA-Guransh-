#include <iostream>
using namespace std;

struct N {
    int v;
    N* l;
    N* r;
};

N* makeT() {
    int x;
    cin >> x;
    if (x == -1) return NULL;
    N* t = new N;
    t->v = x;
    t->l = makeT();
    t->r = makeT();
    return t;
}

int ok(N* t, int mn, int mx) {
    if (!t) return 1;
    if (t->v <= mn || t->v >= mx) return 0;
    return ok(t->l, mn, t->v) && ok(t->r, t->v, mx);
}

int main() {
    N* root = makeT();
    if (ok(root, -1000000000, 1000000000)) cout << "BST";
    else cout << "Not BST";
}