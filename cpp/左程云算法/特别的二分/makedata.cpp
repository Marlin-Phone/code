#include <bits/stdc++.h>
using namespace std;

int main() {
    std::mt19937 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    int n = rng() % 100 + 1; // 数组大小为n
    int v = 100;             // 数组中的数据范围为[0, v)
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << rng() % v << " ";
    }
    cout << endl;
}