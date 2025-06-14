#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define debug(a) cout << #a << " = " << endl

const int N = 2e5 + 10;
int n, c;
vector<int> A(N);
vector<int> B(N);
int sum = 0;

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.begin() + n);

    for (int i = 0; i < n; i++) {
        B[i] = A[i] - c;
    }

    for (int i = 0; i < n; i++) {
        // A = B + C
        int temp = A[i];
        int l = lower_bound(B.begin(), B.begin() + n, temp) - B.begin();
        int r = upper_bound(B.begin(), B.begin() + n, temp) - B.begin();
        sum += r - l;
    }
    cout << sum;

    return;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}