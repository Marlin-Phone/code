#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"
typedef pair<int, int> PII; // 存储坐标

const int N = 110;
int n, m;
int g[N][N]; // 图: 0-空, 1-墙
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool st[N][N];
long long ans = 0;
long long ans0 = 1e9;
int dist[N][N]; // 存每个点到起点的距离 distance n.距离
queue<PII> q;   // 队列

void dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        ans0 = min(ans0, ans);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == 1)
            continue;
        if (st[a][b] == true)
            continue;

        st[a][b] = true;
        ans++;
        dfs(a, b);
        st[a][b] = false;
        ans--;
    }
}
int bfs(int x, int y) {
    memset(dist, -1, sizeof(dist)); // 都初始化为-1
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {    // 队列不空, 继续循环
        auto t = q.front(); // 取出队首
        q.pop();

        int x = t.first;
        int y = t.second;
        // if (t.first == n && t.second == m)
        //     return dist[n][m];

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || a > n || b < 0 || b > m)
                continue;
            if (g[a][b] != 0)
                continue;
            if (dist[a][b] >= 0)
                continue;

            q.push({a, b});
            dist[a][b] = dist[x][y] + 1;

            if (a == n && b == m)
                return dist[n][m];
        }
    }

    return dist[n][m];
}
int main() {
    IOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    // dfs(0, 0);
    // cout << ans0 << endl;

    cout << bfs(1, 1) << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}