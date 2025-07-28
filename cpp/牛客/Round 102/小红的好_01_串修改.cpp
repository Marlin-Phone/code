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
int n;
string str;

long long check(string s, char type) {
    int n = s.size();
    int p = 0;
    long long ops = 0;
    for (int i = 0; i < n; i++) {
        char t_char;
        if (type == 'A') {
            if (i % 2 == 0) {
                t_char = '0';
            } else {
                t_char = '1';
            }
        } else {
            if (i % 2 == 0) {
                t_char = '1';
            } else {
                t_char = '0';
            }
        }
        if (s[i] != t_char) {
            p ^= 1;
        }
        if (i < n - 1) {
            ops += p;
        }
    }
    return ops;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = count(s.begin(), s.end(), '0');
    int t0_A = (n + 1) / 2;
    int t0_B = n / 2;

    bool A_ok = (cnt0 % 2 == t0_A % 2);
    bool B_ok = (cnt0 % 2 == t0_B % 2);

    if (!A_ok && !B_ok) {
        cout << "-1\n";
    } else {
        long long ans = LLONG_MAX;
        if (A_ok) {
            long long opsA = check(s, 'A');
            if (opsA < ans) {
                ans = opsA;
            }
        }
        if (B_ok) {
            long long opsB = check(s, 'B');
            if (opsB < ans) {
                ans = opsB;
            }
        }
        cout << ans << "\n";
    }
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