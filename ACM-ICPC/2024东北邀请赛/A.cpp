// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n, k;
set<int> st;
int ans = 0;

void check() {
    int k0 = k;
    int n0 = n;
    int flag = 0;

    while (k0 && n0 <= 1e9) {
        n0 *= n0;
        if (st.count(n0) == 1) {
            flag = 1;
            break;
        }
        st.insert(n0);
        ans++;
        k0--;
    }
    if (!flag) {
        ans += k0;
    }
}

void solve() {
    cin >> n >> k;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    st.insert(n);

    ans += k;
    ans += 1;

    while (1) {
        if (k == 0) {
            break;
        }
        k--;

        n = sqrt(n);
        // debug(n);
        // debug(k);
        st.insert(n);

        check();

        ans += 1;
        if (n == 1) {
            break;
        }
    }
    cout << ans << endl;
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