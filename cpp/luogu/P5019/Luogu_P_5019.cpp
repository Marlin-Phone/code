// https://www.luogu.com.cn/problem/P5019
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int d[N];
int cnt = 0;
int flag = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 2; i <= n; i++) {
        if (d[i - 1] < d[i]) {
            cnt += d[i] - d[i - 1];
        }
    }
    cnt += d[1];

    // for (int i = 1; i <= n; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    cout << cnt;

    return 0;
}