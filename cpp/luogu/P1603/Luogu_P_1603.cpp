// https://www.luogu.com.cn/problem/P1603
#include <bits/stdc++.h>
using namespace std;

int flag = 0;
int ans_flag[10];
string s[7];
string tofind[30] = {"zero",    "one",     "two",       "three",    "four",
                     "five",    "six",     "seven",     "eight",    "nine",
                     "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                     "twenty",  "a",       "both",      "another",  " first",
                     "second",  "third"};
vector<int> ans;
int n = 0;

int main() {
    for (int i = 1; i <= 6; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 30; j++) {
            if (s[i] == tofind[j] && j <= 20) {
                ans.push_back(j);
                n++;
            } else if (s[i] == tofind[j] && j > 20) {
                if (j == 21) {
                    ans.push_back(1);
                } else if (j == 22) {
                    ans.push_back(2);
                } else if (j == 23) {
                    ans.push_back(1);
                } else if (j == 24) {
                    ans.push_back(1);
                } else if (j == 25) {
                    ans.push_back(2);
                } else if (j == 26) {
                    ans.push_back(3);
                }
                n++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i] *= ans[i];
        ans[i] %= 100;
        if (ans[i] < 10) {
            ans_flag[i] = 1;
        }
    }

    sort(ans.begin(), ans.end());
    if (ans.size() != 0) {
        cout << ans[0];
    }
    for (int i = 1; i < n; i++) {
        if (ans[i] < 10) {
            cout << 0;
        }
        cout << ans[i];
        flag = 1;
    }
    if (flag == 0) {
        cout << 0;
    }

    return 0;
}