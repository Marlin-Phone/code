// https://www.luogu.com.cn/problem/P1303
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
string sa, sb;
int a[N], b[N], c[N];

void atimesb(string &sa, string &sb) {

    for (int i = 0; i < sa.size(); i++) {
        a[i] = sa[sa.size() - i - 1] - '0';
    }
    for (int i = 0; i < sb.size(); i++) {
        b[i] = sb[sb.size() - i - 1] - '0';
    }

    for (int i = 0; i < sb.size(); i++) {
        for (int j = 0; j < sa.size(); j++) {
            c[j + i] += a[j] * b[i];
            if (c[j + i] > 9) {
                c[j + i + 1] += c[j + i] / 10;
                c[j + i] = c[j + i] % 10;
            }
        }
    }
}
int main() {
    cin >> sa;
    cin >> sb;

    atimesb(sa, sb);

    int index = 0;
    for (int i = sa.size() + sb.size() - 1; i >= 0; i--) {
        if (c[i] != 0) {
            index = i;
            break;
        }
    }
    for (int i = index; i >= 0; i--) {
        cout << c[i];
    }

    return 0;
}