#include <iostream>
using namespace std;

struct N {
    int v;
    N* n;
};

int main() {
    int m;
    cin >> m;
    int a[100];
    for (int i = 0; i < m; i++) cin >> a[i];

    N* head = NULL, *p, *t;

    for (int i = 0; i < m; i++) {
        t = new N;
        t->v = a[i];
        t->n = NULL;
        if (!head) head = t;
        else {
            p = head;
            while (p->n) p = p->n;
            p->n = t;
        }
    }

    N* s = head;
    N* f = head;

    while (f && f->n) {
        s = s->n;
        f = f->n->n;
    }

    cout << s->v;
}