// https://luogu.com.cn/problem/P1320
#include <bits/stdc++.h>
using namespace std;

const int N = 210;
string g, s;
int cnt0 = 0, cnt1 = 0;
int flag;

int main() {
    cin >> g;
    int n = g.length();
    // cout << n << " ";

    for (int i = 1; i < n; i++) {
        cin >> s;
        g += s;
    }

    // cout << endl << g << endl;

    cout << n << " ";

    int i = 0;
    while (i < n * n) {
        while (g[i] == '0' && i < n * n) {
            cnt0++;
            i++;
        }
        if (cnt0 == 0 && i == n * n) {
            break;
        }
        cout << cnt0 << " ";
        cnt0 = 0;
        while (g[i] == '1' && i < n * n) {
            cnt1++;
            i++;
        }
        if (cnt1 == 0 && i == n * n) {
            break;
        }
        cout << cnt1 << " ";
        cnt1 = 0;
    }

    // flag = (g[0] == '0') ? 0 : 1;
    // for (int i = 0; i < n * n; i++) {
    //     if (g[i] == '0' && flag == 0) {
    //         cnt0++;
    //         // flag = 0;
    //     } else if (g[i] == '0' && flag == 1) {
    //         cout << cnt1 << " ";
    //         cnt1 = 0;
    //         cnt0++;
    //         flag = 0;
    //     } else if (g[i] == '1' && flag == 1) {
    //         cnt1++;
    //         flag = 1;
    //     } else if (g[i] == '1' && flag == 0) {
    //         cout << cnt0 << " ";
    //         cnt0 = 0;
    //         cnt1++;
    //         flag = 1;
    //     }
    // }
    // if (g[n * n - 1] == '1') {
    //     cout << cnt1 << " ";
    // }
    // if (g[n * n - 1] == '0') {
    //     cout << cnt0 << " ";
    // }

    return 0;
}