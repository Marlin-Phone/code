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
const int mod = 1e9 + 7;
char choice[4] = {'r', 'e', 'd'};
bool is(string &arr, int l, int r) {
    while (l <= r) {
        if (arr[l] == arr[r]) {
            l++;
            r--;
            continue;
        } else {
            return false;
        }
    }
    return true;
}
int dfs(int n, int x, string &arr) {
    if (x > n) {
        int cnt = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = l + 1; r <= n; r++) {
                if (is(arr, l, r)) {
                    cnt++;
                }
                if (cnt > 1) {
                    return 0;
                }
            }
        }
        return cnt == 1 ? 1 : 0;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        arr.push_back(choice[i]);
        ans += dfs(n, x + 1, arr);
        arr.pop_back();
    }
    return ans;
}
int getans(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 3;
    }
    if (n == 3) {
        return 18;
    }
    return (long long)6 * (n + 1) % mod;
}
void solve() {
    // for (int i = 1; i <= 10; i++) {
    //     string arr = " ";
    //     cout << "长度为: " << i << " 答案: " << dfs(i, 1, arr) << endl;
    // }
    cin >> n;
    cout << getans(n) << endl;
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