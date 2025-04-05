// https://luogu.com.cn/problem/P1098
#include <bits/stdc++.h>
using namespace std;
int p1;
/*
p1=1时，对于字母子串，填充小写字母；
p1=2时，对于字母子串，填充大写字母。
这两种情况下数字子串的填充方式相同.
p1=3时，不论是字母子串还是数字字串，
都用与要填充的字母个数相同的星号*来填充。*/
int p2;
/*
填充字符的重复个数。p2=k表示同一个字符要连续填充 k 个。
例如，当 p2=3时，子串d-h 应扩展为 deeefffgggh。
减号两边的字符不变。*/
int p3;
/*
是否改为逆序：p3=1表示维持原来顺序，p3=2表示采用逆序输出，
注意这时候仍然不包括减号两端的字符。例如当 p1=1、p2 =2、
p3=2时，子串 d-h 应扩展为 dggffeeh*/
string s, ans;
int lenans = 0;
bool isnum;
bool isword;

bool check(int i, int j) {
    isnum = false, isword = false;
    if (s[i] >= '0' && s[i] <= '9' && s[j] >= '0' && s[j] <= '9' &&
        s[i] < s[j]) {
        isnum = true;
        return true;
    }
    if (s[i] >= 'a' && s[i] <= 'z' && s[j] >= 'a' && s[j] <= 'z' &&
        s[i] < s[j]) {
        isword = true;
        return true;
    }
    return false;
}
int main() {
    cin >> p1 >> p2 >> p3;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' && check(i - 1, i + 1)) {
            if (p1 == 1) {
                s.erase(i, 1);
                string space;
                for (int k = s[i - 1] + 1; k <= s[i] - 1; k++) {
                    char ch = k;
                    for (int j = 1; j <= p2; j++) {
                        space += ch;
                    }
                }
                if (p3 == 2) {
                    reverse(space.begin(), space.end());
                }
                s.insert(i, space);
            } else if (p1 == 2) {
                s.erase(i, 1);
                string space;
                for (int k = s[i - 1] + 1; k <= s[i] - 1; k++) {
                    char ch = k;
                    ch = toupper(ch);
                    for (int j = 1; j <= p2; j++) {
                        space += ch;
                    }
                }
                if (p3 == 2) {
                    reverse(space.begin(), space.end());
                }
                s.insert(i, space);
            } else if (p1 == 3) {
                s.erase(i, 1);
                string space;
                for (int k = s[i - 1] + 1; k <= s[i] - 1; k++) {
                    for (int j = 1; j <= p2; j++) {
                        space += '*';
                    }
                }
                if (p3 == 2) {
                    reverse(space.begin(), space.end());
                }
                s.insert(i, space);
            }
        }
    }

    cout << s;

    return 0;
}