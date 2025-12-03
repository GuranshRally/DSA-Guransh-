#include <iostream>
using namespace std;

struct N {
    char v;
    N* p;
    N* n;
};

int main() {
    int m;
    cin >> m;

    char a[200];
    for (int i = 0; i < m; i++) cin >> a[i];

    N* head = NULL, *t, *p;

    for (int i = 0; i < m; i++) {
        t = new N;
        t->v = a[i];
        t->n = NULL;
        if (!head) {
            t->p = NULL;
            head = t;
        } else {
            p = head;
            while (p->n) p = p->n;
            p->n = t;
            t->p = p;
        }
    }

    N* l = head;
    N* r = head;

    while (r->n) r = r->n;

    int ok = 1;

    while (l != r && l->p != r) {
        if (l->v != r->v) {
            ok = 0;
            break;
        }
        l = l->n;
        r = r->p;
    }

    if (ok) cout << "Palindrome";
    else cout << "Not Palindrome";
}