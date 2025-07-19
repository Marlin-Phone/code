// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int fm = (1 << n) - 1;

    if (fm > s.size() || s[fm - 1] != '0') {
        cout << "No\n";
        return;
    }

    vector<bool> vis(1 << n, false);
    queue<int> q;

    for (int k = 0; k < n; ++k) {
        int m = 1 << k;
        if (m - 1 < s.size() && s[m - 1] == '0') {
            vis[m] = true;
            q.push(m);
        }
    }

    while (!q.empty()) {
        int m = q.front();
        q.pop();

        if (m == fm) {
            cout << "Yes\n";
            return;
        }

        for (int k = 0; k < n; ++k) {
            if (!(m & (1 << k))) {
                int nm = m | (1 << k);
                if (!vis[nm]) {
                    int idx = nm - 1;
                    if (idx < s.size() && s[idx] == '0') {
                        vis[nm] = true;
                        q.push(nm);
                    }
                }
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
