// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n, k;
string A;
string ans;

string getBinary(int num) {
    string ans;
    while (num != 0) {
        ans += to_string(num % 2);
        num /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool check(int m, int B_cnt1) {
    string temp = getBinary(m);
    int temp_cnt1 = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '1') {
            temp_cnt1++;
        }
    }
    if (temp_cnt1 == B_cnt1) {
        ans = temp;
        return true;
    }
    return false;
}
void solve() {
    cin >> n >> k;
    cin >> A;
    int cnt1 = 0;
    ans = "";

    for (int i = 0; i < n; i++) {
        if (A[i] == '1') {
            cnt1++;
        }
    }
    if (cnt1 == 0) {
        for (int i = 1; i <= k; i++) {
            cout << "0";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < (1 << k); i++) {
        string B = getBinary(i);
        int B_cnt1 = 0;
        // for (int i = 0; i < B.size(); i++) {
        //     if (B[i] == '1') {
        //         B_cnt1++;
        //     }
        // }
        B_cnt1 = __builtin_popcount(i);
        if (B_cnt1 + cnt1 == i) {
            string temp_str = "";
            while (B.size() < k) {
                temp_str += "0";
                k--;
            }
            cout << temp_str;
            cout << B << endl;
            return;
        }
    }
    cout << "None" << endl;
    // for (int i = 0; i < k; i++) { // x^n的个数 | B中1的个数
    //     int temp = cnt1 + i;
    //     if (check(temp, i) == true) {
    //         if (ans.size() > k) {
    //             cout << "None" << endl;
    //             return;
    //         }
    //         while (ans.size() < k) {
    //             cout << "0";
    //             k--;
    //         }
    //         cout << ans << endl;
    //         return;
    //     }
    //     }
    // cout << "None" << endl;
    // return;
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