#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int n, c;
int A[N];
int ans = 0;
int B[N];

signed main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + 1 + n);

    for (int i = 1; i <= n; i++) {
        B[i] = A[i] + c;
    }

    for (int i = 1; i <= n; i++) {
        int target = A[i];
        int l = lower_bound(B + 1, B + 1 + n, target) - B;
        int r = upper_bound(B + 1, B + 1 + n, target) - B;
        ans += r - l;
    }

    cout << ans;

    return 0;
}