#include <bits/stdc++.h>
using namespace std;

const int N = 1;

long long ans = 0;
int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += i * j;
            // cout << ans << endl;
        }
    }

    cout << ans;

    return 0;
}