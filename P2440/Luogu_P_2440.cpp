// https://www.luogu.com.cn/problem/P2440
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 10;
int n, k;      // n 根原木 k 段
int L[N];      // 一根原木的长度
int maxL = -1; // 原木的最大长度
ll maxl = -1;

bool check(int mid) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += L[i] / mid;
    }
    if (sum >= k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> L[i];
        maxL = max(L[i], maxL);
    }

    int l = 0, r = maxL + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    /* 暴力枚举
    for (ll i = 1; i <= maxL; i++) {
        int k0 = 0;
        for (int j = 0; j < n; j++) {
            if (L[j] / i == 0)
                continue;
            k0 += L[j] / i;
        }

        if (k0 >= k) {
            maxl = max(maxl, i);
        }
    }

    cout << maxl;
*/
    return 0;
}