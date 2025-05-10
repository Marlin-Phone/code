// https://ac.nowcoder.com/acm/contest/105623/C
// 要记得开long long
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 2e5 + 10;
int T;
int n;
int a[N];
char S[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> S[i];
        }

        for (int i = 1; i <= n; i++) {
            if (S[i] == '<') {
                if (a[i] >= 0) {
                    ans++;
                    a[i] = -1;
                }
            } else if (S[i] == '>') {
                if (a[i] <= 0) {
                    ans++;
                    a[i] = 1;
                }
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        for (int i = 1; i <= n; i++) {
            if (S[i] == 'Z') {
                if (a[i - 1] * a[i] <= 0) {
                    // cout << "here" << endl;
                    ans++;
                    if (a[i] == 0) {
                        a[i] = a[i - 1];
                    } else {
                        a[i] = a[i - 1];
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}