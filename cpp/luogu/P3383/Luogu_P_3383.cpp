// https://luogu.com.cn/problem/P3383
// 模板 线性筛 埃氏筛 素数
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e8 + 10;
int T = 1;
int n, q;
bool isPrime[N];
int primes[N];
int idx = 1;

void getprime() {
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            int num = i;
            // while()
        }
    }
}
void getPrimes(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
void solve() {
    cin >> n >> q;
    memset(isPrime, true, sizeof(isPrime));
    getPrimes(n);
    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) {
            primes[idx++] = i;
        }
    }
    while (q--) {
        int k;
        cin >> k;
        cout << primes[k] << endl;
    }
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