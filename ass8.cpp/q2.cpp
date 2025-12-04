#include <iostream>
using namespace std;

struct N {
    int v;
    N* l;
    N* r;
};

N* insertT(N* t, int x) {
    if (!t) {
        t = new N;
        t->v = x;
        t->l = t->r = NULL;
    } else if (x < t->v) t->l = insertT(t->l, x);
    else t->r = insertT(t->r, x);
    return t;
}

N* searchR(N* t, int x) {
    if (!t || t->v == x) return t;
    if (x < t->v) return searchR(t->l, x);
    return searchR(t->r, x);
}

N* searchNR(N* t, int x) {
    while (t) {
        if (t->v == x) return t;
        if (x < t->v) t = t->l;
        else t = t->r;
    }
    return NULL;
}

int minT(N* t) {
    while (t->l) t = t->l;
    return t->v;
}

int maxT(N* t) {
    while (t->r) t = t->r;
    return t->v;
}

N* succ(N* root, int x) {
    N* p = NULL;
    N* t = root;
    while (t) {
        if (x < t->v) {
            p = t;
            t = t->l;
        } else t = t->r;
    }
    return p;
}

N* pred(N* root, int x) {
    N* p = NULL;
    N* t = root;
    while (t) {
        if (x > t->v) {
            p = t;
            t = t->r;
        } else t = t->l;
    }
    return p;
}

int main() {
    int n, x;
    cin >> n;
    N* root = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertT(root, x);
    }

    int k;
    cin >> k;

    N* a = searchR(root, k);
    if (a) cout << "FoundR\n"; else cout << "NotFoundR\n";

    N* b = searchNR(root, k);
    if (b) cout << "FoundNR\n"; else cout << "NotFoundNR\n";

    cout << minT(root) << "\n";
    cout << maxT(root) << "\n";

    N* s = succ(root, k);
    if (s) cout << s->v << "\n";
    else cout << -1 << "\n";

    N* p = pred(root, k);
    if (p) cout << p->v << "\n";
    else cout << -1 << "\n";
}