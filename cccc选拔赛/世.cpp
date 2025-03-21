#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);
#define endl "\n"

const int N = 1e5 + 10;
int n, m;
int nums[N];
int l, r, k;
int ans = 0;

int main() {
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    while (m--) {
        int ans = 0;
        cin >> l >> r >> k;
        for (int i = l; i <= r; i++) {
            if (nums[i] <= k) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}