// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

int T = 1;
const int MAX = 505;
int color[MAX][MAX];
int max_p[MAX][MAX];
int temp[MAX][MAX];

void solve() {
    int n, m, c, k;
    cin >> n >> m >> c >> k;

    vector<tuple<int, int, int, int, int, int, int>> stickers;
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2, p, xt, yt;
        cin >> x1 >> y1 >> x2 >> y2 >> p >> xt >> yt;
        stickers.emplace_back(x1, y1, x2, y2, p, xt, yt);
    }

    // 读取图案纸到temp
    for (int i = 1; i <= c; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> temp[i][j];

    memset(color, -1, sizeof(color));

    for (const auto &sticker : stickers) {
        int x1, y1, x2, y2, p, xt, yt;
        tie(x1, y1, x2, y2, p, xt, yt) = sticker;
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                int dx = i - x1, dy = j - y1;
                int cur_color = temp[xt + dx][yt + dy];
                if (p > max_p[i][j]) {
                    max_p[i][j] = p;
                    color[i][j] = cur_color;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j > 1)
                cout << ' ';
            cout << color[i][j];
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}