#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl

int m;
int op, l;
set<int> st;

void solve() {
    cin >> m;
    while (m--) {
        cin >> op >> l;
        switch (op) {
        case 1: {
            if (st.count(l) == 1) {
                cout << "Already Exist" << endl;
            } else {
                st.insert(l);
            }
            break;
        }
        case 2: {
            if (st.size() == 0) {
                cout << "Empty" << endl;
                break;
            }
            auto right = st.lower_bound(l);
            auto left = right;
            if (right == st.begin()) {

            } else {
                --left;
            }
            if (right == st.end()) {
                cout << *left << endl;
                st.erase(left);
                break;
            }
            if (abs((int)*left - l) <= abs((int)*right - l)) {
                cout << *left << endl;
                st.erase(left);
            } else {
                cout << *right << endl;
                st.erase(right);
            }
            break;
        }
        }
    }

    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}