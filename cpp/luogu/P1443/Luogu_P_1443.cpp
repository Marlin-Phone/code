#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 410;
int n, m, x, y;
int g[N][N];
int dist[N][N];
queue<pair<int, int>> q;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};

void bfs(int x, int y) {
    q.push({x, y});
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (dist[a][b] != -1)
                continue;

            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m >> x >> y;

    bfs(x, y);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}