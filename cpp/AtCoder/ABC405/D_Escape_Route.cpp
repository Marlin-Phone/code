// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1005;
int H, W;
char S[N][N];
queue<pair<int, int>> que;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool st[N][N];

void BFS() {
    while (!que.empty()) {
        auto t = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 1 || b < 1 || a > H || b > W) {
                continue;
            }
            if (S[a][b] == '#') {
                continue;
            }
            if (st[a][b] == true) {
                continue;
            }

            if (i == 0) {
                S[a][b] = 'v';
            } else if (i == 1) {
                S[a][b] = '<';
            } else if (i == 2) {
                S[a][b] = '^';
            } else if (i == 3) {
                S[a][b] = '>';
            }

            st[a][b] = true;
            que.push({a, b});
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> S[i][j];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i][j] == 'E') {
                que.push({i, j});
                st[i][j] = true;
            }
        }
    }

    BFS();

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cout << S[i][j];
        }
        cout << endl;
    }
    return 0;
}