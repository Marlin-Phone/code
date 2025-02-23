#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 1;
int T, n, ans, a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        // compute the answer
        cout << ans << '\n';
    }
    return 0;
}