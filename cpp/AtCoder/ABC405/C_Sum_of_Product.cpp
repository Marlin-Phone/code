// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 3e5 + 10;
int n;
int A[N];
int S[N];
int s = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }

    for (int i = n; i >= 1; i--) {
        s += A[i] * (S[i - 1]);
    }

    cout << s;

    return 0;
}