// https://luogu.com.cn/problem/P5250
// set 迭代器的使用
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
int op;
set<int> st;
int length;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--) {
        cin >> op >> length;
        switch (op) {
        case 1: { // 进货
            if (st.count(length) == 1) {
                cout << "Already Exist" << endl;
            } else {
                st.insert(length);
            }
            break;
        }
        case 2: { // 出货
            if (st.empty()) {
                cout << "Empty" << endl;
                break;
            }

            auto it = st.find(length);
            if (it != st.end()) {
                cout << length << endl;
                st.erase(it);
                break;
            }

            auto right = st.lower_bound(length);
            if (right == st.end()) {
                auto last = prev(right);
                cout << *last << endl;
                st.erase(last);
            } else if (right == st.begin()) {
                cout << *right << endl;
                st.erase(right);
            } else {
                auto left = prev(right);
                if (length - *left <= *right - length) {
                    cout << *left << endl;
                    st.erase(left);
                } else {
                    cout << *right << endl;
                    st.erase(right);
                }
            }
            break;
        }
        }
    }

    return 0;
}