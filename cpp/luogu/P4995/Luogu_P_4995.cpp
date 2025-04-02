// https://luogu.com.cn/problem/P4995
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 310;
int n;    // 石头个数
int h[N]; // 第i块石头的高度hi
int tili = 0;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    sort(h, h + 1 + n);

    // for (int i = 0; i <= n; i++) {
    //     cout << h[i] << " ";
    // }
    // cout << endl;

    int l = 0, r = n;
    int me = l;
    while (l != r) {
        if (me == l) {
            tili += abs(h[l] - h[r]) * abs(h[l] - h[r]);
            l++;
            me = r;
        } else {
            tili += abs(h[l] - h[r]) * abs(h[l] - h[r]);
            r--;
            me = l;
        }
    }

    cout << tili;

    return 0;
}