// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int N =
int T = 1;
int a; // A进制
int n; // 最大为n

int get_huiwen(int num) {
    // string str_num = to_string(num);
    // string str_temp = str_num;
    // reverse(str_temp.begin(), str_temp.end());
    // str_num += str_temp;
    // int ans = stoll(str_num);
    // return ans;

    int num0 = num;
    while (num0 > 0) {
        num *= 10;
        num += num0 % 10;
        num0 /= 10;
    }
    return num;
}
int get_huiwen2(int num, int plus) {
    // string str_num = to_string(num);
    // string str_temp = str_num;
    // reverse(str_temp.begin(), str_temp.end());
    // str_num += to_string(plus);
    // str_num += str_temp;
    // int ans = stoll(str_num);
    // return ans;

    int num0 = num;
    num *= 10;
    num += plus;
    while (num0 > 0) {
        num *= 10;
        num += num0 % 10;
        num0 /= 10;
    }
    return num;
}
bool check(int num) {
    string num2;
    while (num > 0) {
        string temp = to_string(num % a);
        num2 += temp;
        num /= a;
    }
    int l = 0, r = num2.size() - 1;
    while (r >= 0 && l < num2.size() && l < r) {
        if (num2[l] != num2[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve() {
    int cnt = 0;
    int sum = 0;
    cin >> a;
    cin >> n;

    string str_a = to_string(a);
    int half_size = str_a.size() + 1;
    // 枚举一半后拼接

    // 偶数
    for (int i = 1; i <= sqrt(n) + 1; i++) {
        int num = get_huiwen(i);
        if (num > n) {
            break;
        }
        if (check(num)) {
            // debug(num);
            sum += num;
            // cnt++;
        }
    }

    // 奇数
    for (int j = 0; j <= 9; j++) {
        for (int i = 1; i <= sqrt(n) + 1; i++) {
            int num = get_huiwen2(i, j);
            if (num > n) {
                break;
            }
            if (check(num)) {
                // debug(num);
                sum += num;
                // cnt++;
            }
        }
    }

    // 0-9
    for (int i = 1; i <= 9 && i <= n; i++) {
        if (check(i)) {
            sum += i;
            // cnt++;
        }
    }
    cout << sum;
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