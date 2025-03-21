#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

const int N = 1e6 + 10;
int n, m;
vector<int> L(N);

// bool check(long long x) {
//     long long sum = 0;
//     for (long long i = 1; i <= n; i++) {
//         sum
//     }
//     cout << "sum = " << sum << endl;
//     if (sum >= m)
//         return true;
//     return false;
// }

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }

    long long sum_Li = 0;
    int max_len = 0;
    for (int x : L) {
        sum_Li += x;
        max_len = max(max_len, x);
    }

    if (sum_Li < m) {
        cout << 0 << '\n';
        return 0;
    }

    int l = 0, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += L[i] / mid;
        }
        if (cnt >= m) {
            l = mid;
            // cout << "l = " << l << endl;
        } else {
            r = mid;
            // cout << "r = " << r << endl;
        }
    }

    cout << l << endl;

    return 0;
}
