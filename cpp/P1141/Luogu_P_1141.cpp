// https://www.luogu.com.cn/problem/P1141
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

const int N = 1e3 + 10;
int n, m;
char g[N][N];
int i0, j0;
queue<pair<int, int>> q, q0;
bool st[N][N];
int ans = 1;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[N][N];

int bfs(int x, int y) {
    vector<pair<int, int>> vec;
    q.push({x, y});
    vec.push_back({x, y});
    st[x][y] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        x = t.first;
        y = t.second;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (st[a][b] == true) {
                continue;
            }
            if (a < 1 || b < 1 || a > n || b > n) {
                continue;
            }
            if (g[x][y] == g[a][b]) {
                continue;
            }

            q.push({a, b});
            vec.push_back({a, b});
            st[a][b] = true;
            ans++;
        }
    }

    for (auto begin = vec.begin(); begin != vec.end(); begin++) {
        auto [x, y] = *begin;
        dist[x][y] = ans;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == 0) {
                ans = 1;
                dist[i][j] = bfs(i, j);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> i0 >> j0;
        cout << dist[i0][j0] << endl;
    }

    return 0;
}