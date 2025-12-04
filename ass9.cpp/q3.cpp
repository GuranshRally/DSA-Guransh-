#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct E { int u, v, w; };

int findp(int p[], int x) {
    if (p[x] == x) return x;
    p[x] = findp(p, p[x]);
    return p[x];
}

void unite(int p[], int r[], int a, int b) {
    a = findp(p, a);
    b = findp(p, b);
    if (a == b) return;
    if (r[a] < r[b]) p[a] = b;
    else if (r[b] < r[a]) p[b] = a;
    else { p[b] = a; r[a]++; }
}

void kruskal(E edges[], int m, int n) {
    sort(edges, edges + m, [](const E &a, const E &b){ return a.w < b.w; });
    int p[1000], r[1000];
    for (int i = 0; i < n; i++) { p[i] = i; r[i] = 0; }
    int cnt = 0;
    int total = 0;
    for (int i = 0; i < m && cnt < n-1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (findp(p, u) != findp(p, v)) {
            unite(p, r, u, v);
            cout << u << " " << v << " " << w << "\n";
            total += w;
            cnt++;
        }
    }
    cout << "Total " << total << "\n";
}

void prim(int g[][1000], int n) {
    int key[1000], parent[1000], used[1000];
    for (int i = 0; i < n; i++) { key[i] = INT_MAX; used[i] = 0; parent[i] = -1; }
    key[0] = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        int u = -1;
        for (int i = 0; i < n; i++) if (!used[i] && (u == -1 || key[i] < key[u])) u = i;
        if (u == -1) break;
        used[u] = 1;
        for (int v = 0; v < n; v++) {
            if (g[u][v] != 0 && !used[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }
    int total = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << " " << g[parent[i]][i] << "\n";
            total += g[parent[i]][i];
        }
    }
    cout << "Total " << total << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;
    E edges[1000];
    int g[1000][1000];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g[i][j] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        if (g[u][v] == 0 || w < g[u][v]) {
            g[u][v] = w;
            g[v][u] = w;
        }
    }
    int ch;
    cin >> ch;
    if (ch == 1) kruskal(edges, m, n);
    else prim(g, n);
}