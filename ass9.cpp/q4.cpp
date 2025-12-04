#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int g[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int s;
    cin >> s;

    int d[100], used[100];
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        used[i] = 0;
    }

    d[s] = 0;

    for (int k = 0; k < n; k++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || d[i] < d[u]))
                u = i;

        if (u == -1) break;

        used[u] = 1;

        for (int v = 0; v < n; v++) {
            if (g[u][v] && d[u] != INT_MAX && d[u] + g[u][v] < d[v])
                d[v] = d[u] + g[u][v];
        }
    }

    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
}