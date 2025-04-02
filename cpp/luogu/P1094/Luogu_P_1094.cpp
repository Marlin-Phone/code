// https://luogu.com.cn/problem/P1094
#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 10;
int w; // 每组纪念品价格之和的上限
int n; // 购买来的总件数G
int cnt = 0;

int main() {
    cin >> w;
    cin >> n;
    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    sort(P.begin(), P.begin() + n);

    int l = 0, r = n - 1;
    while (l < r) { //
        if (P[l] + P[r] <= w) {
            P[r] += P[l];
            P[l] = 0;
            l++;
        } else {
            r--;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << P[i] << " ";
    // }

    for (int i = 0; i < n; i++) {
        if (P[i] != 0) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}