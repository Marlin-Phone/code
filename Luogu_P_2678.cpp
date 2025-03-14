#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int l, n, m;
int D[N];
int dx[N];
int ans = 0;
int flag[N];
int res = 1e9;

bool check(int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dx[i] < x) {
            ans++;
        }
    }

    cout << "ans = " << ans << endl;
    if (ans <= m) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
        dx[i] = D[i] - D[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << dx[i] << " ";
    }
    cout << endl;

    int left = 0, right = l;
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
            cout << "left = " << left << endl;
        } else {
            right = mid;
            cout << "right = " << right << endl;
        }
    }

    cout << left << endl;

    for (int i = 1; i <= n; i++) {
        if (dx[i] > left) {
            res = min(res, dx[i]);
        }
    }

    cout << res;

    return 0;
}