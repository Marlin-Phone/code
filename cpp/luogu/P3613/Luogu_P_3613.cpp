// https://www.luogu.com.cn/problem/P3613
#include <bits/stdc++.h>
using namespace std;

int n;
int q;
int i, j, k;
int d;
map<int, int> mp[100010];

int main() {
    cin >> n >> q;
    // vector<vector<int>> arr(n + 1, vector<int>(1e5 + 10, 0));

    while (q--) {
        cin >> d;
        if (d == 1) {
            cin >> i >> j >> k;
            if (k != 0) {
                // arr[i][j] += k;
                mp[i][j] = k;
            } else if (k == 0) {
                // arr[i][j] = 0;
            }
        } else {
            cin >> i >> j;
            // cout << arr[i][j] << endl;
            cout << mp[i][j] << endl;
        }
    }

    return 0;
}