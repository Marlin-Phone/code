#pragma GCC optimmize("O3", "inline", "omit-frame-pointer", "unroll-loops",    \
                      "fast-math")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
int nums[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
int max_sum = -1;

void solve() {
    string str;
    cin >> str;
    for (int i = 0; i < 26; i++) {
        int sum = 0;
        for (int j = 0; j < str.size(); j++) {
            int idx = (str[j] - 'A' + i) % 26;
            // cout << idx << endl;
            // cout << nums[idx] << endl;
            sum += nums[idx];
        }
        max_sum = max(max_sum, sum);
    }
    cout << max_sum << endl;a
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}