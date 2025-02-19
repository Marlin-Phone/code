#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PII pair<int, int>

const int N = 110;
int n, m;
int g[N][N];
int dist[N][N];
int ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<PII> q;

int bfs(int x, int y) {
    memset(dist, -1, sizeof(dist));
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        x = t.first;
        y = t.second;

        if (x == n - 1 && y == m - 1)
            return dist[n - 1][m - 1];

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (g[a][b] == 1)
                continue;
            if (dist[a][b] >= 0)
                continue;

            q.push({a, b});
            dist[a][b] = dist[x][y] + 1;

            // if (a == n - 1 && b == m - 1)
            //     return dist[n - 1][m - 1];
        }
    }

    return dist[n - 1][m - 1]; // 无解时仍然输出-1
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    ans = bfs(0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans << endl;

    return 0;
}