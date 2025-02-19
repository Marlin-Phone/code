#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> PII;

const int N = 110;
int n, m;       // n行m列
int g[N][N];    // 图: 0-空, 1-墙
int dist[N][N]; // 存每个点到起点的距离
int ans = 0;    // 最短距离
queue<PII> q;   // 队列
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    memset(dist, -1, sizeof(dist)); // 都初始化为-1
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {    // 队列不空, 继续循环
        auto t = q.front(); // 取出队首
        q.pop();            // 出队

        if (t.first == n && t.second == m)
            return dist[n][m];

        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a <= 0 || a > n || b <= 0 || b > m)
                continue;
            if (g[a][b] == 1)
                continue;
            if (dist[a][b] >= 0)
                continue;

            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1;

            if (a == n && b == m)
                return dist[n][m];
        }
    }

    return dist[n][m];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    ans = bfs(1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans << endl;

    return 0;
}