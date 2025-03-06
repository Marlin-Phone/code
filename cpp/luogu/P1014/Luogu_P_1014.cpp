// https://www.luogu.com.cn/problem/P1014
#include <iostream>
using namespace std;

// int 的取值范围在 -2,147,483,648 到 2,147,483,647
const int N = 1e7 + 10;

void function(int n) {
    int x = 1, y = 1, count = 1;
    while (n > count) {
        n = n - count;
        count++;
    }
    if (count % 2 == 0) {
        cout << n << "/" << count - n + 1;
    } else {
        cout << count - n + 1 << "/" << n;
    }
}

int main() {
    int n, ans = 0;
    cin >> n;
    function(n);

    return 0;
}