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

    N* prev = NULL;
    N* cur = head;
    N* nxt;

    while (cur) {
        nxt = cur->n;
        cur->n = prev;
        prev = cur;
        cur = nxt;
    }

    head = prev;

    p = head;
    while (p) {
        cout << p->v;
        if (p->n) cout << "->";
        p = p->n;
    }
    cout << "->NULL";
}