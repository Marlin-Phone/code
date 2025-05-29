// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n, k;
int a[N], b[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int flag = -1; // b数组全为-1
        int sum;
        int minnum = 1e9;
        int maxnum = -1;

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            minnum = min(minnum, a[i]);
            maxnum = max(maxnum, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] != -1) {
                flag = 1; // b数组不全为-1
                sum = b[i] + a[i];
            }
        }
        if (flag == 1) {
            int flag1 = 0;
            // cout << "test1" << endl;
            for (int i = 0; i < n; i++) {
                if (b[i] != -1) {
                    if (a[i] + b[i] != sum) {
                        cout << 0 << endl;
                        flag1 = 1;
                        break;
                    } else {
                        continue;
                    }
                } else {
                    if (sum <= a[i] + k && a[i] <= sum) {
                        continue;
                    } else {
                        cout << 0 << endl;
                        flag1 = 1;
                        break;
                    }
                }
            }
            if (flag1 == 0) {
                cout << 1 << endl;
            }
        } else {
            cout << minnum + k - maxnum + 1 << endl;
        }
    }
    return 0;
}