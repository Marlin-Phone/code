// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n;
string str, target;

void solve() {
    unordered_multiset<char> umset1, umset2, umset3, umset4;

    cin >> str >> target;

    // char ch = str[0];
    int idx = 0;
    while (str[idx] != '/') {
        idx++;
    }
    string str1 = str.substr(0, idx);
    int size = str.size() - str1.size() - 1;
    string str2 = str.substr(idx + 1, size);

    for (int i = 0; i < str1.size(); i++) {
        umset1.insert(str1[i]);
    }
    for (int i = 0; i < str2.size(); i++) {
        umset2.insert(str2[i]);
    }

    idx = 0;
    while (target[idx] != '/') {
        idx++;
    }
    string str3 = target.substr(0, idx);
    int size = target.size() - str3.size() - 1;
    string str4 = target.substr(idx + 1, size);

    for (int i = 0; i < str3.size(); i++) {
        umset3.insert(str3[i]);
    }
    for (int i = 0; i < str4.size(); i++) {
        umset4.insert(str4[i]);
    }

    // for (auto it1 = umset1.begin(); it1 != umset1.end(); it1++){
    //     if(umset3.find(*it1) == umset3.end()){ // 没找到
    //         if(umset4.find())
    //     }
    // }
    for (auto it3 = umset3.begin(); it3 != umset3.end(); it3++) {
        for (auto it1 = umset1.begin(); it1 != umset1.end(); it1++) {
            while (umset1.find(*it3) != umset1.end()) { // 没找到
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}