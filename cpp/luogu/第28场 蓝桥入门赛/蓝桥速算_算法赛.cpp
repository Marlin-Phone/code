#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int A[N];
int sum = 0;
int n, q;
int jianum;

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int num = r - l;
        if (num % 2 == 0) {
            jianum = l + num / 2;
        } else {
            jianum = -(num / 2 + 1);
        }
        sum += jianum;
    }

    cout << sum;

    return 0;
}