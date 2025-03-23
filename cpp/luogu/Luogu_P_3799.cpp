// 纯抄题解
// https://www.luogu.com.cn/problem/P3799
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
long long n;
long long a[N];
const long long kMod = 1e9 + 7;
const int kMaxn = 1e6 + 10;
long long maxa = -1;
long long num[N];
long long ans;

long long C(long long x, long long k) {
    // k = 1 或 2 特判写法.
    return (k == 1ll ? x : x * (x - 1ll) / 2ll) % kMod;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(a[i], maxa);
        num[a[i]]++;
    }

    for (int i = 2; i <= maxa; i++) { // 枚举两根相等的边
        if (num[i] >= 2ll) {
            long long times = C(num[i], 2ll) % kMod; // 求出组合数
            for (int j = 1; j <= i / 2; j++) {
                if (j != i - j && num[j] >= 1 && num[i - j] >= 1) {
                    ans += times * C(num[j], 1) * C(num[i - j], 1) % kMod;
                }
                if (j == i - j && num[j] >= 2) {
                    ans += times * C(num[j], 2) % kMod;
                }
                ans %= kMod;
            }
        }
    }

    cout << ans << endl;

    return 0;
}