// https://www.luogu.com.cn/problem/P1328
#include <bits/stdc++.h>
using namespace std;
#define int long long

//  剪刀    石头    布  蜥蜴人  斯波克
//  0       1       2   3       4

const int N = 200;
int a[N];      //
int b[N];      //
int n, na, nb; // n次猜拳 na周期 nb周期
int ascore = 0, bscore = 0;

int check(int a, int b) {
    if (a == 0) {
        if (b == 0)
            return 0;
        if (b == 1 || b == 4)
            return -1;
        if (b == 2 || b == 3)
            return 1;
    }
    if (a == 1) {
        if (b == 1)
            return 0;
        if (b == 2 || b == 4)
            return -1;
        if (b == 0 || b == 3)
            return 1;
    }
    if (a == 2) {
        if (b == 2)
            return 0;
        if (b == 0 || b == 3)
            return -1;
        if (b == 1 || b == 4)
            return 1;
    }
    if (a == 3) {
        if (b == 3)
            return 0;
        if (b == 0 || b == 1)
            return -1;
        if (b == 2 || b == 4)
            return 1;
    }
    if (a == 4) {
        if (b == 4)
            return 0;
        if (b == 2 || b == 3)
            return -1;
        if (b == 0 || b == 1)
            return 1;
    }
}
signed main() {
    cin >> n >> na >> nb;
    for (int i = 1; i <= na; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= nb; i++) {
        cin >> b[i];
    }

    for (int i = 1, j = 1, k = 1; i <= n; i++, j++, k++) {
        if (j == na + 1)
            j = 1;
        if (k == nb + 1)
            k = 1;
        if (check(a[j], b[k]) == 1) {
            ascore++;
        } else if (check(a[j], b[k]) == -1) {
            bscore++;
        } else {
        }
    }

    cout << ascore << " " << bscore;

    return 0;
}