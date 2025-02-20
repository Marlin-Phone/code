// https://www.luogu.com.cn/problem/P1332
// 多元BFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 10;
const int N0 = 510;
int n, m, a, b;
int num_a[N][2]; // 感染源位置
int num_b[N][2]; // 0,1为领主位置 2为领主感染时间
int dist[N0][N0];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (dist[a][b] >= 0)
                continue;

            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dist, -1, sizeof(dist));

    cin >> n >> m >> a >> b;
    for (int i = 0; i < a; i++) { // 遍历感染源位置
        cin >> num_a[i][0] >> num_a[i][1];
    }
    for (int i = 0; i < b; i++) { // 遍历领主的位置
        cin >> num_b[i][0] >> num_b[i][1];
    }

    for (int i = 0; i < a; i++) {
        q.push({num_a[i][0], num_a[i][1]});
        dist[num_a[i][0]][num_a[i][1]] = 0;
    }

    bfs();

    for (int i = 0; i < b; i++) {
        cout << dist[num_b[i][0]][num_b[i][1]] << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}