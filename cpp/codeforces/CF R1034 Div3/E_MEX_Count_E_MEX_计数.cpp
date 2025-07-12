#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(n + 2, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] <= n) {
                freq[a[i]]++;
            }
        }

        int M0 = 0;
        while (freq[M0] > 0) {
            M0++;
        }

        vector<int> res(n + 2, 0);

        for (int m = 0; m < M0; m++) {
            long long L = freq[m];
            long long R = n - m;
            if (L <= R) {
                res[L]++;
                if (R + 1 <= n) {
                    res[R + 1]--;
                }
            }
        }

        if (n - M0 >= 0) {
            res[0]++;
            if (n - M0 + 1 <= n + 1) {
                res[n - M0 + 1]--;
            }
        }

        vector<int> ans(n + 1, 0);
        int cur = 0;
        for (int k_val = 0; k_val <= n; k_val++) {
            cur += res[k_val];
            ans[k_val] = cur;
        }

        for (int k_val = 0; k_val <= n; k_val++) {
            cout << ans[k_val] << " ";
        }
        cout << endl;
    }
    return 0;
}