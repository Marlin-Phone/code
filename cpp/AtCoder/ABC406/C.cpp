// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 3e5 + 10;
int T = 1;
int n;
int cnt = 0;
int A[N];
int flag[N];
int d[N];
int s[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 2; i <= n - 1; i++) {
            if (A[i - 1] > A[i] && A[i] < A[i + 1]) {
                d[++cnt] = i;
            }
            if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
                d[++cnt] = i;
            }
            if (A[i] > A[i - 1]) {
                s[i] = s[i - 1] + 1;
            } else {
                s[i] = s[i - 1];
            }
        }

        d[cnt + 1] = n;
        int ans = 0;
        for (int i = 2; i <= cnt; i++) {
            ans += (s[d[i - 1]] - s[d[i - 2]]) * (d[i + 1] - d[i]);
        }
        cout << ans;
    }
    return 0;
}