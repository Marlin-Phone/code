// https://www.luogu.com.cn/problem/P1106
#include <bits/stdc++.h>
using namespace std;

const int N = 300;
string n;
int k;
bool st[N];

int main() {
    cin >> n;
    cin >> k;
    while (k) {
        int i = 0;
        while (n[i] <= n[i + 1]) {
            i++;
        }
        n.erase(i, 1);
        k--;
    }

    while (n[0] == '0' && n.length() > 1) {
        n.erase(0, 1);
    }

    cout << n;

    return 0;
}