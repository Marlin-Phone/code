// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e3 + 10;
int n;
int a[N];
int s[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    set<int> st;
    int res = 1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int r = s[j] - s[i - 1];
            if (!st.empty()) {
                auto it = st.lower_bound(r);
                res = min(res, abs(*it - r));
                if (it != st.begin()) {
                    res = min(res, abs(*(--it) - r));
                }
            }
        }
        for (int j = 1; j <= i; j++) {
            st.insert(s[i] - s[j - 1]);
        }
    }
    cout << res << endl;

    return 0;
}