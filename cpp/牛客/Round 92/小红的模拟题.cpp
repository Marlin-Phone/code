// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e3 + 10;
int n, m;
char g[N][N];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
queue<char> que;
queue<pair<int, int>> qu;

// void bfs(int x, int y) {
//     qu.push({x, y});

//     while (!qu.empty()) {
//         auto t = qu.front();
//         qu.pop();

//         for (int i = 0; i < 2; i++) {
//             int a = t.first + dx[i];
//             int b = t.second + dy[i];

//             if (a < 1 || b < 1 || a > n || b > m) {
//                 continue;
//             }
//             if (g[a][b] == '#') {
//                 continue;
//             }

//             if (i == 0) {
//                 que.push('D');
//             } else if (i == 1) {
//                 que.push('S');
//             }

//             if (a == n && b == m) {
//                 while (!que.empty()) {
//                     cout << que.front();
//                     que.pop();
//                 }
//                 return;
//             }

//             qu.push({a, b});
//         }
//     }
// }
// void dfs(int x, int y) {
//     if (x == n && y == m) {
//         while (!que.empty()) {
//             cout << que.front();
//             que.pop();
//         }
//         return;
//     }

//     for (int i = 0; i < 2; i++) {
//         int a = x + dx[i];
//         int b = y + dy[i];

//         if (a < 1 || b < 1 || a > n || b > m) {
//             continue;
//         }
//         if (g[a][b] == '#') {
//             continue;
//         }

//         if (i == 0) {
//             que.push('D');
//         } else if (i == 1) {
//             que.push('S');
//         }

//         dfs(a, b);

//         que.pop();
//     }
// }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int xflag;
    int yflag;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                xflag = i;
                yflag = j;
            }
        }
    }
    // dfs(1, 1);
    // cout << endl;
    // bfs(1, 1);

    if (xflag != 1 && yflag != m) {
        for (int i = 1; i <= m - 1; i++) {
            cout << 'D';
        }
        for (int i = 1; i <= n - 1; i++) {
            cout << 'S';
        }
    } else if (xflag == 1) {
        cout << 'S';
        for (int i = 1; i <= n - 2; i++) {
            cout << 'S';
        }
        for (int i = 1; i <= m - 1; i++) {
            cout << 'D';
        }
    } else if (yflag == m) {
        for (int i = 1; i <= n - 1; i++) {
            cout << "S";
        }
        for (int i = 1; i <= m - 1; i++) {
            cout << 'D';
        }
    }

    return 0;
}