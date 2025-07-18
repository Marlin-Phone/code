// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long
// #define MOD 1000000007

const int MOD = 1e9 + 7;
const int N = 700;
int T = 1;
int n, q;
int a[N][N];
int B[N][N];
int C[N][N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    while (q--) {
        int k;
        int row[N], col[N];
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> row[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> col[i];
        }

        vector<int> rows, cols;
        int ptr = 0;
        for (int i = 1; i <= n; i++) { // 剩余行
            if (ptr < k && row[ptr] == i)
                ptr++;
            else
                rows.push_back(i);
        }
        ptr = 0;
        for (int i = 1; i <= n; i++) { // 剩余列
            if (ptr < k && col[ptr] == i)
                ptr++;
            else
                cols.push_back(i);
        }

        int m = rows.size();
        int detB_main = 1, detB_anti = 1;
        for (int i = 0; i < m; i++) {
            // 主对角线
            detB_main = (detB_main * a[rows[i]][cols[i]]) % MOD;
            // 反对角线
            int anti_j = cols[m - 1 - i];
            detB_anti = (detB_anti * a[rows[i]][anti_j]) % MOD;
        }
        int detB = (detB_main - detB_anti + MOD) % MOD;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                C[i][j] = a[row[i]][col[j]];
            }
        }

        int fc = 1;
        for (int i = 0; i < k; i++) {
            fc = (fc * C[i][i]) % MOD;
        }
        int fc0 = 1;
        for (int i = 0; i < k; i++) {
            fc0 = (fc0 * C[i][k - i - 1]) % MOD;
            fc0 = (fc0 * C[i][k - i - 1]) % MOD;
        }
        fc = (fc - fc0 + MOD) % MOD;
        int ans = (fc * detB) % MOD;
        cout << (ans % MOD + MOD) % MOD << endl;
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