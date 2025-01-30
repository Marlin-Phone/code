// https://www.luogu.com.cn/problem/P2415
#include <bits/stdc++.h>
using namespace std;

int main() {
    int s[40];
    int n = 0;
    long long ans = 0;
    while (scanf("%d", &s[n]) != EOF) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        ans = ans + s[i] * pow(2, n - 1);
    }

    cout << ans << endl;

    return 0;
}