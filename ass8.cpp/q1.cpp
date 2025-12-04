#include <iostream>
using namespace std;

struct N {
    int v;
    N* l;
    N* r;
};

N* makeTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;
    N* t = new N;
    t->v = x;
    t->l = makeTree();
    t->r = makeTree();
    return t;
}

void pre(N* t) {
    if (!t) return;
    cout << t->v << " ";
    pre(t->l);
    pre(t->r);
}

void in(N* t) {
    if (!t) return;
    in(t->l);
    cout << t->v << " ";
    in(t->r);
}

void post(N* t) {
    if (!t) return;
    post(t->l);
    post(t->r);
    cout << t->v << " ";
}

int main() {
    N* root = makeTree();
    pre(root);
    cout << "\n";
    in(root);
    cout << "\n";
    post(root);
}