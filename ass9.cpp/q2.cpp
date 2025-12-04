#include <iostream>
using namespace std;

int g[100][100], vis[100];

void dfs(int x, int n) {
    cout << x << " ";
    vis[x] = 1;
    for (int i = 0; i < n; i++) {
        if (g[x][i] && !vis[i]) dfs(i, n);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int s;
    cin >> s;

    dfs(s, n);
}