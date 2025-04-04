// https://luogu.com.cn/problem.P1009
#include <bits/stdc++.h>
using namespace std;

const int N = 120;
int n;
int a[N]; // 阶乘和
int b[N]; // 阶乘
int lena = 1, lenb = 1;

void fuc(int n) { // 求n!, b数组已经存储(n - 1)!, 所以现在只要乘以n就可以了
    int carry = 0;
    for (int i = 1; i < N - 10; i++) {
        b[i] = b[i] * n + carry;
        carry = b[i] / 10;
        b[i] %= 10;
    }
    // while(carry > 0){
    //     b[++lenb] = carry % 10;
    //     carry /= 10;
    // }
}
void add() { // 求a+b存储到a中
    int carry = 0;
    for (int i = 1; i < N; i++) {
        int product = a[i] + b[i] + carry;
        carry = product / 10;
        a[i] = product % 10;
    }
}
int main() {
    cin >> n;

    a[1] = b[1] = 1;
    for (int i = 2; i <= n; i++) {
        fuc(i); // 求i的阶乘
        add();  // 累加i的阶乘
    }

    int index = N - 1;
    while (a[index] == 0 && index > 1) {
        index--;
    }

    for (int i = index; i >= 1; i--) {
        cout << a[i];
    }

    return 0;
}