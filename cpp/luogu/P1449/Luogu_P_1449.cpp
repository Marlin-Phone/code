// https://www.luogu.com.cn/problem/P1449
// 用栈来求后缀表达式
// 注意数字的处理
#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
string s;
int num = 0;

int main() {
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num *= 10;
            num += s[i] - '0';
        } else if (s[i] == '.') {
            stk.push(num);
            num = 0;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            int x;
            switch (s[i]) {
            case '+': {
                x = a + b;
                break;
            }
            case '-': {
                x = a - b;
                break;
            }
            case '*': {
                x = a * b;
                break;
            }
            case '/': {
                x = a / b;
            }
            }
            stk.push(x);
        }
    }

    cout << stk.top();

    return 0;
}