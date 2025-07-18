// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;

int getnum(int n, int x, int y) {
    int mid = (1LL << (n - 1));

    if (n == 1) {
        if (x == 1 && y == 1) {
            return 1;
        } else if (x == 2 && y == 2) {
            return 2;
        } else if (x == 2 && y == 1) {
            return 3;
        } else {
            return 4;
        }
    }

    if (x <= mid && y <= mid) {
        return getnum(n - 1, x, y);
    } else if (x > mid && y > mid) {
        return (1LL << (2 * n - 2)) + getnum(n - 1, x - mid, y - mid);
    } else if (x > mid && y <= mid) {
        return 2 * (1LL << (2 * n - 2)) + getnum(n - 1, x - mid, y);
    } else {
        return 3 * (1LL << (2 * n - 2)) + getnum(n - 1, x, y - mid);
    }
}
pair<int, int> getxy(int n, int num) {
    int a, b;
    int x = 0, y = 0;
    if (n == 1) {
        if (num == 1) {
            return {1, 1};
        } else if (num == 2) {
            return {2, 2};
        } else if (num == 3) {
            return {2, 1};
        } else {
            return {1, 2};
        }
    }
    if (num <= (1LL << (2 * n - 2))) {
        auto [a, b] = getxy(n - 1, num);
        x = a, y = b;
    } else if (num <= 2 * (1LL << (2 * n - 2))) {
        auto [a, b] = getxy(n - 1, num - 1 * (1LL << (2 * n - 2)));
        x = a + (1LL << (n - 1)), y = b + (1LL << (n - 1));
    } else if (num <= 3 * (1LL << (2 * n - 2))) {
        auto [a, b] = getxy(n - 1, num - 2 * (1LL << (2 * n - 2)));
        x = a + (1LL << (n - 1)), y = b;
    } else {
        auto [a, b] = getxy(n - 1, num - 3 * (1LL << (2 * n - 2)));
        x = a, y = b + (1LL << (n - 1));
    }

    return {x, y};
}
void solve() {
    cin >> n;
    int q;
    cin >> q;
    while (q--) {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        if (ch1 == '-') {
            int x, y;
            cin >> x >> y;
            cout << getnum(n, x, y) << endl;
        } else {
            int d;
            cin >> d;
            auto [x, y] = getxy(n, d);
            cout << x << " " << y << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}