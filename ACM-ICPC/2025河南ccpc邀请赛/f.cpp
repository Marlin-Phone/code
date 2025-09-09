#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;
const int N = 1010;
const int inf = 1e9;
char g[N][N];
int st[N][N];
int dist[N][N];
int n, m;
queue<pair<int, int>> q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs1(int x, int y, int mk) {
    st[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && !st[a][b]) {
            if (g[a][b] == '.')
                bfs1(a, b, mk);
            else if (mk == 0) {
                q.push({a, b});
                dist[a][b] = 1;
                st[a][b] = 1;
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    while (q.size())
        q.pop();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            st[i][j] = 0;
            dist[i][j] = inf;
        }
    }

    bfs1(1, 1, 0);

    if (st[n][m]) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            st[i][j] = 0;
        }
    }

    bfs1(n, m, 1);
    int ans = n + m - 2;

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        // cout<<"i: "<<x<<" j: "<<y<<" dist: "<<dist[x][y]<<endl;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 1 && a <= n && b >= 1 && b <= m) {

                if (st[a][b] == 0 && dist[x][y] + 1 < dist[a][b]) {
                    dist[a][b] = dist[x][y] + 1;
                    q.push({a, b});
                } else if (st[a][b] == 1 && dist[x][y] < dist[a][b]) {
                    dist[a][b] = dist[x][y];
                    ans = min(ans, dist[a][b]);
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}