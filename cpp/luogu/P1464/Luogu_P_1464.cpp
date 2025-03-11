// https://www.luogu.com.cn/problem/P1464
#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int mem[N][N][N];

long long w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) // 防止数组越界导致RE
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (mem[a][b][c])
        return mem[a][b][c];

    else if (a < b && b < c)
        mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                       w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return mem[a][b][c];
}

int main() {
    long long a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        else
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}