#include <iostream>
using namespace std;

struct N {
    int v;
    N* n;
};

N* head = NULL;

void addBeg(int x) {
    N* t = new N;
    t->v = x;
    t->n = head;
    head = t;
}

void addEnd(int x) {
    N* t = new N;
    t->v = x;
    t->n = NULL;
    if (!head) head = t;
    else {
        N* p = head;
        while (p->n) p = p->n;
        p->n = t;
    }
}

void addBefore(int x, int y) {
    if (!head) return;
    if (head->v == y) {
        addBeg(x);
        return;
    }
    N* p = head;
    while (p->n && p->n->v != y) p = p->n;
    if (p->n) {
        N* t = new N;
        t->v = x;
        t->n = p->n;
        p->n = t;
    }
}

void addAfter(int x, int y) {
    N* p = head;
    while (p && p->v != y) p = p->n;
    if (p) {
        N* t = new N;
        t->v = x;
        t->n = p->n;
        p->n = t;
    }
}

void delBeg() {
    if (!head) return;
    N* t = head;
    head = head->n;
    delete t;
}

void delEnd() {
    if (!head) return;
    if (!head->n) {
        delete head;
        head = NULL;
        return;
    }
    N* p = head;
    while (p->n->n) p = p->n;
    delete p->n;
    p->n = NULL;
}

void delVal(int x) {
    if (!head) return;
    if (head->v == x) {
        delBeg();
        return;
    }
    N* p = head;
    while (p->n && p->n->v != x) p = p->n;
    if (p->n) {
        N* t = p->n;
        p->n = p->n->n;
        delete t;
    }
}

void searchVal(int x) {
    N* p = head;
    int pos = 1;
    while (p) {
        if (p->v == x) {
            cout << pos << "\n";
            return;
        }
        p = p->n;
        pos++;
    }
    cout << -1 << "\n";
}

void show() {
    N* p = head;
    while (p) {
        cout << p->v << " ";
        p = p->n;
    }
    cout << "\n";
}

int main() {
    int ch, x, y;

    while (true) {
        cin >> ch;

        if (ch == 1) {
            cin >> x;
            addBeg(x);
        }

        else if (ch == 2) {
            cin >> x;
            addEnd(x);
        }

        else if (ch == 3) {
            cin >> x >> y;
            addBefore(x, y);
        }

        else if (ch == 4) {
            cin >> x >> y;
            addAfter(x, y);
        }

        else if (ch == 5) delBeg();

        else if (ch == 6) delEnd();

        else if (ch == 7) {
            cin >> x;
            delVal(x);
        }

        else if (ch == 8) {
            cin >> x;
            searchVal(x);
        }

        else if (ch == 9) show();

        else if (ch == 10) break;
    }
}