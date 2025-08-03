#include <bits/stdc++.h>
using namespace std;

int main() {
    std::mt19937 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    int T = rng() % 10 + 1;
    cout << T << endl;
    while (T--) {
        int n = rng() % 10 + 1; // 数组大小为n
        // int v = 100;             // 数组中的数据范围为[0, v)
        int k = rng() % 20 + 1;
        cout << n << " " << k << endl;
        for (int i = 1; i <= n; i++) {
            cout << rng() % 2;
        }
        cout << endl;
    }
}