// https://luogu.com.cn/problem/P1335
// BFS 最短路
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 210;
int n;
int A, B;
int k[N];
queue<pair<int, int>> q;
int dx[2] = {1, -1};

void bfs(int x) {
    bool vis[N] = {false};
    vis[x] = true;
    int cnt = 0;
    q.push({x, 0}); // 按按钮的次数cnt;

    while (!q.empty()) {
        auto t = q.front(); // t为当前所在的楼层
        q.pop();

        for (int i = 0; i < 2; i++) {
            int a = t.first + dx[i] * k[t.first];

            if (a < 1 || a > n) {
                continue;
            }
            if (vis[a] == true) {
                continue;
            }

            // cout << "a = " << a << endl;
            // cout << "B = " << B << endl;

            if (a == B) {
                cout << t.second + 1;
                return;
            }
            vis[a] = true;
            // cout << "a = " << a << "cnt = " << cnt << endl;
            q.push({a, t.second + 1});
        }
    }

    cout << -1;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> A >> B;
    if (A == B) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    bfs(A);

    return 0;
}