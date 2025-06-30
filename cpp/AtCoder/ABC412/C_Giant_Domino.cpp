// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n;
int S[N];
int minnum = 1e9 + 10;
int cnt = 0;

bool check(int mid) {
    if (S[mid] <= 2 * minnum) {
        return true;
    }

    return false;
}
void solve() {
    cnt = 2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    if (S[1] * 2 >= S[n]) {
        cout << 2 << endl;
        return;
    }
    minnum = S[1]; // 初始化
    sort(S + 1 + 1, S + n);
    int l = 1, r = n;
    bool reach = false;
    while (1) { // 当前重量*2<最终一个的重量时, 需要继续添加骨牌
        l = 1, r = n;
        int best = 1;

        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (S[mid] <= 2 * minnum) {
                best = mid;
                l = mid;
            } else {
                r = mid;
            }
        }
        if (S[best] <= minnum) {
            cout << -1 << endl;
            return;
        }
        if (best == 1) {
            cout << -1 << endl;
            return;
        }
        cnt++;
        minnum = max(minnum, S[l]);
        if (2 * minnum >= S[n]) {
            reach = true;
            break;
        }
    }
    if (reach) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
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