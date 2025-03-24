// https://www.luogu.com.cn/problem/P3613
#include <bits/stdc++.h>
using namespace std;

int n, q;
int op;
int i, j, k;
map<int, map<int, int>> mp;

int main() {
    cin >> n >> q;
    while (q--) {
        cin >> op;
        switch (op) {
        case 1: {
            cin >> i >> j >> k;
            mp[i][j] = k;
            break;
        }
        case 2: {
            cin >> i >> j;
            cout << mp[i][j] << endl;
            break;
        }
        }
    }

    return 0;
}