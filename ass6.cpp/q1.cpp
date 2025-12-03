#include <iostream>
using namespace std;

struct C {
    int v;
    C* n;
};

struct D {
    int v;
    D* p;
    D* n;
};

C* ch = NULL;
D* dh = NULL;

void cAddFirst(int x) {
    C* t = new C;
    t->v = x;
    if (!ch) {
        ch = t;
        t->n = t;
    } else {
        C* p = ch;
        while (p->n != ch) p = p->n;
        t->n = ch;
        p->n = t;
        ch = t;
    }
}

void cAddLast(int x) {
    C* t = new C;
    t->v = x;
    if (!ch) {
        ch = t;
        t->n = t;
    } else {
        C* p = ch;
        while (p->n != ch) p = p->n;
        p->n = t;
        t->n = ch;
    }
}

void cAddBefore(int x, int y) {
    if (!ch) return;
    if (ch->v == y) {
        cAddFirst(x);
        return;
    }
    C* p = ch;
    while (p->n != ch && p->n->v != y) p = p->n;
    if (p->n != ch) {
        C* t = new C;
        t->v = x;
        t->n = p->n;
        p->n = t;
    }
}

void cAddAfter(int x, int y) {
    C* p = ch;
    if (!p) return;
    do {
        if (p->v == y) {
            C* t = new C;
            t->v = x;
            t->n = p->n;
            p->n = t;
            return;
        }
        p = p->n;
    } while (p != ch);
}

void cDel(int x) {
    if (!ch) return;
    if (ch->v == x) {
        if (ch->n == ch) {
            delete ch;
            ch = NULL;
            return;
        }
        C* p = ch;
        while (p->n != ch) p = p->n;
        C* t = ch;
        ch = ch->n;
        p->n = ch;
        delete t;
        return;
    }
    C* p = ch;
    while (p->n != ch && p->n->v != x) p = p->n;
    if (p->n != ch) {
        C* t = p->n;
        p->n = p->n->n;
        delete t;
    }
}

void cSearch(int x) {
    if (!ch) {
        cout << -1 << "\n";
        return;
    }
    int pos = 1;
    C* p = ch;
    do {
        if (p->v == x) {
            cout << pos << "\n";
            return;
        }
        pos++;
        p = p->n;
    } while (p != ch);
    cout << -1 << "\n";
}

void cShow() {
    if (!ch) {
        cout << "\n";
        return;
    }
    C* p = ch;
    do {
        cout << p->v << " ";
        p = p->n;
    } while (p != ch);
    cout << "\n";
}

void dAddFirst(int x) {
    D* t = new D;
    t->v = x;
    t->p = NULL;
    t->n = dh;
    if (dh) dh->p = t;
    dh = t;
}

void dAddLast(int x) {
    D* t = new D;
    t->v = x;
    t->n = NULL;
    if (!dh) {
        t->p = NULL;
        dh = t;
    } else {
        D* p = dh;
        while (p->n) p = p->n;
        p->n = t;
        t->p = p;
    }
}

void dAddBefore(int x, int y) {
    D* p = dh;
    while (p && p->v != y) p = p->n;
    if (!p) return;
    if (p == dh) {
        dAddFirst(x);
        return;
    }
    D* t = new D;
    t->v = x;
    t->n = p;
    t->p = p->p;
    p->p->n = t;
    p->p = t;
}

void dAddAfter(int x, int y) {
    D* p = dh;
    while (p && p->v != y) p = p->n;
    if (!p) return;
    D* t = new D;
    t->v = x;
    t->p = p;
    t->n = p->n;
    if (p->n) p->n->p = t;
    p->n = t;
}

void dDel(int x) {
    D* p = dh;
    while (p && p->v != x) p = p->n;
    if (!p) return;
    if (p == dh) dh = dh->n;
    if (p->p) p->p->n = p->n;
    if (p->n) p->n->p = p->p;
    delete p;
}

void dSearch(int x) {
    D* p = dh;
    int pos = 1;
    while (p) {
        if (p->v == x) {
            cout << pos << "\n";
            return;
        }
        pos++;
        p = p->n;
    }
    cout << -1 << "\n";
}

void dShow() {
    D* p = dh;
    while (p) {
        cout << p->v << " ";
        p = p->n;
    }
    cout << "\n";
}

int main() {
    int mode, ch, x, y;
    cin >> mode;

    while (true) {
        cin >> ch;

        if (mode == 1) {
            if (ch == 1) cin >> x, cAddFirst(x);
            else if (ch == 2) cin >> x, cAddLast(x);
            else if (ch == 3) cin >> x >> y, cAddBefore(x, y);
            else if (ch == 4) cin >> x >> y, cAddAfter(x, y);
            else if (ch == 5) cin >> x, cDel(x);
            else if (ch == 6) cin >> x, cSearch(x);
            else if (ch == 7) cShow();
            else if (ch == 8) break;
        }

        if (mode == 2) {
            if (ch == 1) cin >> x, dAddFirst(x);
            else if (ch == 2) cin >> x, dAddLast(x);
            else if (ch == 3) cin >> x >> y, dAddBefore(x, y);
            else if (ch == 4) cin >> x >> y, dAddAfter(x, y);
            else if (ch == 5) cin >> x, dDel(x);
            else if (ch == 6) cin >> x, dSearch(x);
            else if (ch == 7) dShow();
            else if (ch == 8) break;
        }
    }
}