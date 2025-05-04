#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e5 + 10;
int n, w;
vector<int> a(N);

int compute(int x) {
    int res = x * w;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > x) {
            res += a[i] - x;
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[i] = max(a[i] - (i - 1), 1ll * 0); // Transform prices
    }

    int left = 0, right = 1e9;
    while (left + 3 < right) {
        int m1 = (left * 2 + right) / 3;
        int m2 = (left + right * 2) / 3;
        int c1 = compute(m1);
        int c2 = compute(m2);
        if (c1 < c2) {
            right = m2;
        } else {
            left = m1;
        }
    }

    int minans = 1e18;
    for (int x = left; x <= right; ++x) {
        minans = min(minans, compute(x));
    }

    cout << minans << endl;

    return 0;
}