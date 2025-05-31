// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define MOD 998244353

const int N = 3e5 + 10;
int T0 = 1;
int n;
int A[N];
int T[N];
int S[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T0--) {
        cin >> n;
        T[0] = 1;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            S[i] = S[i - 1] + A[i] % MOD;
            T[i] = T[i - 1] * A[i] % MOD;
        }

        for (int l = 1; l <= n; l++) {
            while (l)
        }
    }
    return 0;
}