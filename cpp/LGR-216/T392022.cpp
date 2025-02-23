#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

typedef struct {
    int x, y, k_this;
} Node;

const int N = 1e3 + 10;
int T; // 测试数据组数
int dist[N][N];
queue<Node> q;
// (a, b)工作室所在十字路口的横纵坐标
// k, l 自行车的使用次数限制和自行车的移动距离
int a0, b0, k, l;
int dx[8] = {-1, 0, 1, 0};
int dy[8] = {0, 1, 0, -1};

int bfs(int x, int y) {
    Node node;
    node.x = x;
    node.y = y;
    node.k_this = k;
    q.push({node.x, node.y, node.k_this});
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;

    while (!q.empty()) {
        auto t = q.front();
        // cout << "t.k_this = " << t.k_this << endl;
        q.pop();

        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                int a = t.x + dx[i];
                int b = t.y + dy[i];

                if (a < 0 || b < 0 || dist[a][b] != -1)
                    continue;

                dist[a][b] = dist[t.x][t.y] + 1;
                q.push({a, b, t.k_this});

                if (dist[a0][b0] != -1)
                    return dist[a0][b0];
            } else if (i >= 4) {
                if (t.k_this <= 0) {
                    continue;
                }
                int a = t.x + dx[i - 4] * l;
                int b = t.y + dy[i - 4] * l;

                if (a < 0 || b < 0 || dist[a][b] != -1) {
                    continue;
                }

                dist[a][b] = dist[t.x][t.y];
                q.push({a, b, t.k_this - 1});

                if (dist[a0][b0] != -1)
                    return dist[a0][b0];
            }
        }
    }

    return -1;
}
int main() {
    IOS;

    // cout << "text1" << endl;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a0 >> b0 >> k >> l;
        cout << bfs(0, 0) << endl;
        for (int m = 0; m <= a0; m++) {
            for (int n = 0; n <= b0; n++) {
                cout << dist[m][n] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}