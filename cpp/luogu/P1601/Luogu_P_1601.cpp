#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
string sa, sb;
int a[N], b[N];
int c[N];
int n;

void aplusb(string &sa, string &sb) {
    for (int i = 0; i < sa.size(); i++) {
        a[i] = sa[sa.size() - i - 1] - '0';
    }
    for (int i = 0; i < sb.size(); i++) {
        b[i] = sb[sb.size() - i - 1] - '0';
    }

    n = max(sa.size(), sb.size()); // 高了一位
    for (int i = 0; i < n; i++) {
        c[i] += a[i] + b[i];
    }
    for (int i = 0; i < n; i++) {
        if (c[i] > 9) {
            c[i + 1] += c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
}
int main() {
    cin >> sa;
    cin >> sb;
    aplusb(sa, sb);

    if (c[n] != 0) {
        cout << c[n];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << c[i];
    }

    return 0;
}