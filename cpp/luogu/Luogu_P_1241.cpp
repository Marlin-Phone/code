// https://www.luogu.com.cn/problem/P1241
#include <bits/stdc++.h>
using namespace std;

string s;
bool pd[1000000] = {0}; // 显式初始化

struct Node {
    char k;
    int pos; // 存储括号位置
} z[1000000];
int top = 0;

int main() {
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            z[top].k = s[i];
            z[top].pos = i; // 存储左括号位置
            top++;
        } else {
            if (top > 0 && ((s[i] == ')' && z[top - 1].k == '(') ||
                            (s[i] == ']' && z[top - 1].k == '['))) {
                pd[i] = true;              // 标记右括号匹配
                pd[z[top - 1].pos] = true; // 标记左括号匹配
                top--;
            }
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (pd[i]) {
            cout << s[i];
        } else {
            if (s[i] == '(' || s[i] == ')')
                cout << "()";
            else if (s[i] == '[' || s[i] == ']')
                cout << "[]";
        }
    }

    return 0;
}
