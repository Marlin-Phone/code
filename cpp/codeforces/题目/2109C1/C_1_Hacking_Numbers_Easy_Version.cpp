// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define int long long

// const int N =
int T = 1;
int n;

int add(int y) {
    cout << "add " << y << endl;
    int x;
    cin >> x;
    return x;
}
int mul(int y) {
    cout << "mul " << y << endl;
    int x;
    cin >> x;
    return x;
}
int dix(int y) {
    cout << "div " << y << endl;
    int x;
    cin >> x;
    return x;
}
int digit() {
    cout << "digit " << endl;
    int x;
    cin >> x;
    return x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        mul(9);
        digit();
        digit();
        add(n - 9);
        cout << "!" << endl;
        int x;
        cin >> x;
    }
    return 0;
}