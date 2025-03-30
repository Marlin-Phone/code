#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int n, m;
int S[N];       // i和i+1首歌的好听值之和Si
int a[N], b[N]; // 听第ai首歌bi次
int cnt[N];     // n首歌各自听过的次数
int ans = 0;

signed main() {
    cin >> n >> m; // 听歌数量和次数
    for (int i = 1; i <= n - 1; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        cnt[a[i]] += b[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << cnt[i] << endl;
    // }

    for (int i = 1; i <= n; i++) {
        ans += cnt[i] * S[i];
        cnt[i + 1] -= cnt[i];
    }

    if (cnt[n] == 0) {
        cout << ans;
    } else {
        cout << "Impossible";
    }

    return 0;
}