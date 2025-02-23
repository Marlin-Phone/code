#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

int f[MAX_N];

void precompute() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < MAX_N; ++i) {
        f[i] = (f[i - 1] + 1LL * (i - 1) * f[i - 2]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }

    return 0;
}