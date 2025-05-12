// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
int T;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        vector<int> a;
        cin >> n;
        int temp, val;

        for (int i = 1; i <= n; i++) {
            cin >> temp;
            temp = abs(temp);
            a.push_back(temp);
        }
        val = a[0];
        sort(a.begin(), a.end());

        // for (int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        int idx = lower_bound(a.begin(), a.end(), val) - a.begin();
        idx++;
        // cout << idx << endl;

        int zhong = (a.size() + 1) / 2;
        // cout << "zhong = " << zhong << endl;
        // cout << a.size() - idx + 1 << endl;
        if (idx <= zhong || a.size() - idx + 1 >= zhong) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}