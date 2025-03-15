// https://www.luogu.com.cn/problem/P4554
#include <bits/stdc++.h>
using namespace std;

typedef struct Node_ {
    int x, y;
    int cost;
} Node;
const int N = 510;
int n, m;
char g[N][N];
int x_1, y_1, x_2, y_2; // 起点终点坐标
queue<Node> q;          // 队列
int st[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    memset(st, 0, sizeof(st));
    while (!q.empty()) {
        q.pop();
    }
    q.push(Node{x, y, 0});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i];
            int b = t.y + dy[i];

            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (st[a][b] == 1)
                continue;

            int tcost = 0;
            st[a][b] = 1;
            if (g[t.x][t.y] != g[a][b]) {
                tcost = 1;
            }
            q.push(Node{a, b, t.cost + tcost});

            if (a == x_2 && b == y_2) {
                cout << t.cost + tcost << endl;
                return;
            }
        }
    }
}
int main() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }

        cin >> x_1 >> y_1 >> x_2 >> y_2;

        bfs(x_1, y_1);
    }

    return 0;
}