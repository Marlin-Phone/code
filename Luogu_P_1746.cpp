#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define endl "\n"

const int N = 1e3 + 10;
int n;
char g[N][N];
queue<pair<int, int>> q;
int dist[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int x1, y1, x2, y2;

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

            if (a < 1 || a > n || b < 1 || b > n)
                continue;
            if (g[a][b] == '1')
                continue;
            if (dist[a][b] >= 0)
                continue;

            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1;
            if (a == x2 && b == y2)
                return dist[a][b];
        }
    }

    return dist[x2][y2];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;

    cout << bfs(x1, y1) << endl;

    return 0;
}