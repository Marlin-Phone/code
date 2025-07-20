// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
int T = 1;
int n, m;
vector<string> vstr;
int cntc[N][N];
const int LEFT = 1, RIGHT = 2, UP = 4, DOWN = 8;

void solve() {
    vstr.clear();
    int cnt = 0;
    int cntd = 0;
    memset(cntc, 0, sizeof(cntc));

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        vstr.push_back(temp);
    }

    if (vstr[0][m - 1] != '.') {
        cout << "No" << endl;
        return;
    }

    int total_c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vstr[i][j] == '.') {
                if (!(i == 0 && j == m - 1)) {
                    // cout << "Here" << endl;
                    cout << "No" << endl;
                    return;
                }
            } else if (vstr[i][j] == 'C') {
                total_c++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch = vstr[i][j];
            if (ch == '.') {
                cntd++;
            }
            if (ch == 'C') {
                cnt++;
            }
            if (ch == 'L') {
                if (j == 0) {
                    cout << "No" << endl;
                    return;
                }
                if (vstr[i][j - 1] == 'C') {
                    // cntc[i][j - 1]++;
                    cntc[i][j - 1] |= LEFT;
                    continue;
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
            if (ch == 'R') {
                if (j == m - 1) {
                    cout << "No" << endl;
                    return;
                }
                if (vstr[i][j + 1] == 'C') {
                    // cntc[i][j + 1]++;
                    cntc[i][j + 1] |= RIGHT;
                    continue;
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
            if (ch == 'U') {
                if (i == 0) {
                    cout << "No" << endl;
                    return;
                }
                if (vstr[i - 1][j] == 'C') {
                    // cntc[i - 1][j]++;
                    cntc[i - 1][j] |= UP;
                    continue;
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
            if (ch == 'D') {
                if (i == n - 1) {
                    cout << "No" << endl;
                    return;
                }
                if (vstr[i + 1][j] == 'C') {
                    // cntc[i + 1][j]++;
                    cntc[i + 1][j] |= DOWN;
                    continue;
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vstr[i][j] == 'C') {
                int ref = cntc[i][j];
                // 有效组合只有：5(上+左),6(上+右),9(下+左),10(下+右)
                if (!(ref == 5 || ref == 6 || ref == 9 || ref == 10)) {
                    cout << "No" << endl;
                    return;
                }
            } else if (cntc[i][j] != 0) {
                // cout << "Here" << endl;
                cout << "No" << endl;
                return;
            }
        }
    }

    // debug(cnt);
    // debug((n * m - 1) / 3);
    if (cnt != (n * m - 1) / 3) {
        cout << "No" << endl;
        return;
    }
    if (cntd != 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}