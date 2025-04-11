// https://luogu.com.cn/problem/P8782
// 贪心 | MOD取余
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int n;  // 最高进制
int Ma; // X进制数A的位数
int Mb;
int a[N] = {0};
int b[N] = {0}; //
int c[N] = {0};
int jinzhi[N];
int jinzhi0[N];
int ans = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> Ma;
    for (int i = 1; i <= Ma; i++) {
        cin >> a[i];
    }
    cin >> Mb;
    for (int i = 1; i <= Mb; i++) {
        cin >> b[i];
    }
    reverse(a + 1, a + 1 + Ma);
    reverse(b + 1, b + 1 + Mb);

    jinzhi[0] = 1;
    jinzhi0[0] = 1;
    for (int i = 1; i <= max(Ma, Mb); i++) {
        c[i] = a[i] - b[i];
        jinzhi[i] = max(max(a[i], b[i]) + 1, 2ll); // 贪心
        jinzhi0[i] = jinzhi[i];
        jinzhi0[i] = jinzhi0[i] * jinzhi0[i - 1] % MOD;
        // cout << "jinzhi[" << i << "] = " << jinzhi[i] << endl;
    }

    for (int i = 1; i <= max(Ma, Mb); i++) {
        ans += (jinzhi0[i - 1] * c[i]) % MOD;
        ans %= MOD;
    }

    ans = (ans + MOD) % MOD;

    cout << ans;

    return 0;
}