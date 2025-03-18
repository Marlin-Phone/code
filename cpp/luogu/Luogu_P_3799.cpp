#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int length[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> length[i];
    }
    // 组合数
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= (n - i + 1);
        ans /= i;
    }
    cout << ans << endl;

    return 0;
}