#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int where;

int calculate(string str);

int f(string &s, int i) {
    int cur = 0;
    vector<int> numbers;
    vector<char> ops;
    while (i < s.size() && s[i] != ')') {
        if (s[i] >= '0' && s[i] <= '9') {
            cur = cur * 10 + s[i++] - '0';
        } else if (s[i] != '(') {
            // 遇到了运算符 + - * /
            push(numbers, ops, cur, s[i++]);
            cur = 0;
        } else {
            // i (.....)
            // 遇到了左括号！
            cur = f(s, i + 1);
            i = where + 1;
        }
    }
    push(numbers, ops, cur, '+');
    where = i;
    return compute(numbers, ops);
}

void push(vector<int> &numbers, vector<char> &ops, int cur, char op) {
    int n = numbers.size();
    if (n == 0 || ops[n - 1] == '+' || ops[n - 1] == '-') {
        numbers.push_back(cur);
        ops.push_back(op);
    } else {
        int topNumber = numbers.back();
        char topOp = ops.back();
        if (topOp == '*') {
            numbers.back() = topNumber * cur;
        } else {
            numbers.back() = topNumber / cur;
        }
        ops.back() = op;
    }
}

int compute(vector<int> &numbers, vector<char> &ops) {
    int n = numbers.size();
    int ans = numbers[0];
    for (int i = 1; i < n; i++) {
        ans += ops[i - 1] == '+' ? numbers[i] : -numbers[i];
    }
    return ans;
}

int calculate(string str) {
    where = 0;
    return f(str, 0);
}

void solve() {
    string str;
    cin >> str;
    cout << calculate(str) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}