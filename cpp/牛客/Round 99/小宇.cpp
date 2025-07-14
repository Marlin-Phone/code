// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n;

void solve() {
    int ans = 0;
    map<int, int> cnt, mp;
    cin >> n;

    vector<int> a(n + 10, 2e9);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        mp[a[i]] = i;
    }

    int r = n;
    while (r >= 1 && cnt[a[r]] == 1 && a[r] < a[r + 1] && a[r] >= r) {
        // cnt[r]++;
        r--;
        // cout << "Here" << endl;
    }
    // debug(r);

    set<int> st;
    for (int i = 1; i <= r; i++) {
        st.insert(a[i]);
    }
    ans = st.size();
    for (auto x : st) {
        if (cnt[x] == 1 && mp[x] == x) {
            ans--;
        }
    }

    cout << ans << endl;
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