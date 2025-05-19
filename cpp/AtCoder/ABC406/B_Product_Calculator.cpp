// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long

const int N = 110;
int T = 1;
int n, k;
int A[N];
int ans = 1;

bool check(int ans, int ai) {
    // int cnt = 0;
    // int ans0 = ans; // ans * ai
    // while (ans0 != 0) {
    //     ans0 /= 10;
    //     cnt++;
    // }
    // if (cnt > k) {
    //     return false;
    // }
    // return true;
    int temp = 1;
    for (int i = 1; i <= k; i++) {
        temp *= 10;
    }
    temp--;
    if (ans > (temp / ai)) {
        return false;
    } else {
        return true;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            // ans *= A[i];
            if (check(ans, A[i]) == false) {
                ans = 1;
            } else {
                ans *= A[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}