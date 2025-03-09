// https://www.luogu.com.cn/problem/P2241
#include <iostream>
using namespace std;

long long n, m;
long long minnum;
long long sum;
long long ans;

int main() {
    cin >> n >> m;
    minnum = min(n, m);
    ans = n * m * (n + 1) * (m + 1) / 4;
    for (int i = 0; i < minnum; i++) {
        sum = sum + (n - i) * (m - i);
    }
    cout << sum << " " << ans - sum;

    return 0;
}