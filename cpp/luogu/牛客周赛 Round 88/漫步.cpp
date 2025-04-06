// https://luogu.com.cn/problem/P10424
//
#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int N = 100;
int T;
int x;
int y;

bool check(int num, int z) {
    int length = 0;
    int stz[N] = {0};
    int stn[N] = {0};
    for (int i = 1; z > 0; i++) {
        stz[i] = z % 2;
        z /= 2;
        length++;
    }
    for (int i = 1; num > 0; i++) {
        stn[i] = num % 2;
        num /= 2;
    }
    for (int i = 1; i <= length; i++) {
        if (stz[i] == 1) {
            if (stn[i] != 1) {
                return false;
            }
        }
    }

    return true;
}
signed main() {
    cin >> T;
    while (T--) {
        int flag = 0;
        cin >> x;
        for (int z = 1; z < x; z *= 2) {
            int num = x + z;
            if (check(num, z)) {
                cout << z << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}