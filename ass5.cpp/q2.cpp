#include <iostream>
using namespace std;

struct N {
    int v;
    N* n;
};

int main() {
    int a[100], m, k;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    cin >> k;

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

    int c = 0;
    while (head && head->v == k) {
        t = head;
        head = head->n;
        delete t;
        c++;
    }

    p = head;
    while (p && p->n) {
        if (p->n->v == k) {
            t = p->n;
            p->n = p->n->n;
            delete t;
            c++;
        } else p = p->n;
    }

    cout << c << "\n";

    p = head;
    while (p) {
        cout << p->v;
        if (p->n) cout << "->";
        p = p->n;
    }
}