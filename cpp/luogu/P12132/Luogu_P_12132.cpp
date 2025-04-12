// https://luogu.com.cn/problem/P12132
// 思维
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e5 + 10;
int n;
int A[N];
int cnt = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] > 1) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}