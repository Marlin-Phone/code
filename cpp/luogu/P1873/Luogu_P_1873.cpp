// https://www.luogu.com.cn/problem/P1873
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m;
long long H[N];

bool check(long long x) {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        sum += max(0ll, H[i] - x);
    }
    if (sum >= m)
        return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    int l = 0, r = 4e5 + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}