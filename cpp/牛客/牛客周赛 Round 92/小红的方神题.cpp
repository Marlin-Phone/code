// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1;
        return 0;
    }

    vector<int> vec;
    vec.push_back(1);
    for (int i = n; i > 1; i--) {
        vec.push_back(i);
    }
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;

    return 0;
}