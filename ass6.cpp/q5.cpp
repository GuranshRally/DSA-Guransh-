#include <iostream>
using namespace std;

struct N {
    int v;
    N* n;
};

int main() {
    int m;
    cin >> m;

    int a[200];
    for (int i = 0; i < m; i++) cin >> a[i];

    int flag;
    cin >> flag;

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

    if (flag == 1) {
        p = head;
        while (p->n) p = p->n;
        p->n = head;
    }

    p = head;
    N* q = head;

    while (q && q->n) q = q->n;

    if (q && q->n == head) cout << "Circular";
    else cout << "Not Circular";
}