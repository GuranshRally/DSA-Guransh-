#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int g[100][100] = {0};
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int s;
    cin >> s;

    int vis[100] = {0};
    queue<int> q;

    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < n; i++) {
            if (g[x][i] && !vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}