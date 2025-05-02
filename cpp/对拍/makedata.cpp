#include <bits/stdc++.h>
using namespace std;

int main() {
    std::mt19937 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    int n = rng() % 100 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << rng() % 10 + 1 << " ";
    }
    cout << endl;
}