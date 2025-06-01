// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

// const int N =
int T = 1;
int n;
string str;
stack<char> st;

void solve() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        st.push(str[i]);
        if (st.size() >= 3) {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            char c = st.top();
            st.pop();
            if (!(a == b && b == c)) {
                st.push(c);
                st.push(b);
                st.push(a);
            }
        }
    }
    string ans;
    while (st.size()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << "NAN";
    } else {
        cout << ans;
    }

    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}