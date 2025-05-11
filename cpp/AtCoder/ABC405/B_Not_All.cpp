// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 110;
int n, m;
int nums[N];
int cnt[N];
int cnt0[N];
int maxcnt = 1e9;
queue<int> que;

bool check() { // 判断是否满足区间包含条件
    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) {
            return false;
        }
    }

    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }

    for (int i = 1; i <= m; i++) { // 特判
        if (cnt[i] == 0) {
            cout << 0;
            return 0;
        }
    }

    for (int i = n; i >= 1; i--) {
        cnt[nums[i]]--;
        if (check() == false) {
            cout << n - i + 1;
            return 0;
        }
    }

    return 0;
}