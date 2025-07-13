// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 4e5 + 10;
int T = 1;
int n;
int a[N];
// int weizhi[N];
map<int, vector<int>> weizhi;
int l[N], r[N];

int f(int k) {
    int l = 1, r;
    while (a[l] != k) {
        l++;
    }
    r = l + 1;
    while (a[r] != k) {
        r++;
    }

    return r - l - 1;
}
int getQuan() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += f(i);
    }
    return sum;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (l[a[i]] == 0) {
            l[a[i]] = i;
        } else {
            r[a[i]] = i;
        }
        // weizhi[a[i]].push_back(i);
    }
    int initial_ans = 0;
    for (int i = 1; i <= n; i++) {
        initial_ans += (r[i] - l[i]);
    }
    initial_ans -= n;

    int best_gain = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (a[i] == a[i + 1]) {
            continue;
        }
        int x = a[i], y = a[i + 1];
        int other_x = (i == l[x]) ? r[x] : l[x];
        int other_y = (i + 1 == l[y]) ? r[y] : l[y];
        int term1 = abs(other_x - (i + 1)) + abs(other_y - i);
        int term2 = (r[x] - l[x]) + (r[y] - l[y]);
        int improve = term1 - term2;
        best_gain = max(improve, best_gain);
    }
    // // 需要把离得近的两个值放的尽量远
    // // 权值就是相等的两个值之间其它位置的个数
    // for (auto it : weizhi) {
    //     int a = it.second[0];
    //     int b = it.second[1];
    // }
    if (best_gain < 0) {
        best_gain = 0;
    }
    cout << initial_ans + best_gain;
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