// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 2e5 + 10;
int n, m;
int temp;
int nums[N];
int ans = 0;
int maxans = -1;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        nums[temp]++;
    }
    int l = 0, r = 1;
    while (l <= n && r <= n) {
        if (ans + nums[r] < m) {
            ans += nums[r];
            // cout << "r" << endl;
            // cout << "nums[" << r << "] = " << nums[r] << endl;
            r++;
        } else {
            ans -= nums[l];
            maxans = max(maxans, nums[l]);
            // cout << "l = " << l << endl;
            // cout << "nums[" << l << "] = " << nums[l] << endl;
            l++;
        }
        // maxans = max(maxans, nums[l]);
        // cout << "maxans = " << maxans << endl;
    }
    if (maxans >= m) {
        cout << m;
    } else {
        cout << maxans;
    }

    // cout << (maxans >= m) ? m : maxans;

    return 0;
}