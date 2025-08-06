#include <bits/stdc++.h>
using namespace std;

int main() {
    std::mt19937 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    int k = rng() % 20 + 1; // 数组大小为n
    int v = 20;             // 数组中的数据范围为[0, v)

    cout << k << endl;
    for (int i = 1; i <= k; i++) {
        cout << rng() % v << " ";
    }
    cout << endl;
    int n = rng() % 100 + 101;
    int m = rng() % 100 + 1;
    int x = rng() % 100 + 1;
    cout << n << " " << m << " " << x << endl;
}