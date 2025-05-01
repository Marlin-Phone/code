// https://luogu.com.cn/problem/P3370
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
set<string> st;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        st.insert(temp);
    }

    cout << st.size();

    return 0;
}