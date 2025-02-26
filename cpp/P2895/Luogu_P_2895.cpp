// https://www.luogu.com.cn/problem/P2895
#include <bits/stdc++.h>
using namespace std;

class NUM {
  public:
    int x, y, t;
};

const int N = 5e4 + 10;
int M;
int g[310][310];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[310][310];

int bfs(int x, int y) {
    q.push({x, y});
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 0 || b < 0)
                continue;
            if (dist[a][b] != -1)
                continue;

            dist[a][b] = dist[t.first][t.second] + 1;
            if (dist[a][b] >= g[a][b])
                continue;
            q.push({a, b});

            if (g[a][b] == 0x3f3f3f3f)
                return dist[a][b];
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(g, 0x3f, sizeof(g));
    int x, y, t;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> t;
        g[x][y] = min(g[x][y], t);
        for (int j = 0; j < 4; j++) {
            int a = x + dx[j];
            int b = y + dy[j];

            if (a < 0 || a > 301 || b < 0 || b > 301)
                continue;
            g[a][b] = min(g[a][b], t); // 焦土取小值
        }
    }

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << bfs(0, 0) << endl;

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}