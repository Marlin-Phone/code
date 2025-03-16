// https://www.luogu.com.cn/problem/P1029
#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int ans = 0;

int __lcm(int a, int b) { return a * b / __gcd(a, b); }

int main() {
    cin >> x >> y;
    n = x * y;
    // 公式: 最大公约数 * 最小公倍数 = 两数的乘积
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && __gcd(i, n / i) == x && __lcm(i, n / i) == y) {
            ans++;
        }
    }
    ans *= 2;
    if (x == y) {
        ans--;
    }
    cout << ans << endl;

    return 0;
}