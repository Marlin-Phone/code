// https://www.luogu.com.cn/problem/P2367
#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
int n, p;
long long scores[N];
long long diff[N];
long long minscore = 1e18;

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
        diff[i] = scores[i] - scores[i - 1];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << scores[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << diff[i] << " ";
    // }
    // cout << endl;

    while (p--) {
        int x, y, z;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }

    for (int i = 1; i <= n; i++) {
        scores[i] = scores[i - 1] + diff[i]; // 前缀和
        minscore = min(minscore, scores[i]);
        // cout << scores[i] << " ";
    }
    // cout << endl;
    cout << minscore << endl;

    return 0;
}