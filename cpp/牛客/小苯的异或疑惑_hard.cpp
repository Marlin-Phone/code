// https://ac.nowcoder.com/acm/contest/68572/M
// 异或的性质: a^a = 0, a^a^a = a
//             -> a异或a(自己)2k次值为0, 2k+1次值为1
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 2e5 + 10;
int n;
int a[N];
int sum = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum ^= a[i];
    }
    if ((n - 1) % 2 == 0) {
        cout << 0;
        return 0;
    }

    cout << sum;

    return 0;
}