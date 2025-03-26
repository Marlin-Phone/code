// https://www.luogu.com.cn/problem/P2676
#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int n, b;
int H[N];
long long S;
int ans = 0;

bool cmp(int &a, int &b) { return a > b; }
int main() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    sort(H + 1, H + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        if (S >= b) {
            break;
        }
        ans++;
        S += H[i];
    }
    cout << ans;

    return 0;
}