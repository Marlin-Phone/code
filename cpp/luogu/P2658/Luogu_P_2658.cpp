// https://www.luogu.com.cn/problem/P2658
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, m;
int high[N][N];
int flag[N][N];
int cnt_flag = 0; // 统计路标总数
queue<pair<int, int>> q;
int x, y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int st[N][N];
int cnt = 0;

bool check(int mid) {
    memset(st, 0, sizeof(st));
    // 将q设置为空
    while (!q.empty()) {
        q.pop();
    }
    int cnt = 1;
    st[x][y] = 1;
    q.push({x, y});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 1 || b < 1 || a > n || b > m)
                continue;
            if (abs(high[a][b] - high[t.first][t.second]) > mid)
                continue;
            if (st[a][b] == 1)
                continue;

            // cout << "a:" << a << " b:" << b << endl;

            // cout << "cnt = " << cnt << endl;
            // cout << "cnt_flag = " << cnt_flag << endl;
            st[a][b] = 1;
            q.push({a, b});
            if (flag[a][b] == 1) {
                cnt++;
                // cout << "cnt:" << cnt << endl;
                if (cnt == cnt_flag) {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> high[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> flag[i][j];
            if (flag[i][j] == 1) {
                cnt_flag++;
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << flag[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    bool break_ = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (flag[i][j] == 1) {
                x = i;
                y = j;
                break_ = true;
                break;
            }
        }
        if (break_)
            break;
    }

    int l = -1, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
            // cout << "r:" << mid << endl;
        } else {
            l = mid;
            // cout << "l:" << mid << endl;
        }
    }

    cout << r;

    return 0;
}