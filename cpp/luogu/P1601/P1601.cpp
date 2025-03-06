// https://www.luogu.com.cn/problem/P1601
// 高精度加法
#include <iostream>
#include <string>
using namespace std;

const int N = 1e3 + 10;

int main() {
    string a, b;
    int n;
    int numa[N], numb[N], num[N] = {0};

    cin >> a >> b;

    // 将字符串a, b逆序输入数组numa, numb中
    for (int i = 0; i < a.length(); i++) {
        numa[a.length() - i - 1] = a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        numb[b.length() - i - 1] = b[i] - '0';
    }

    // 计算numa, numb各位之和
    n = a.length() > b.length() ? a.length() : b.length();
    for (int i = 0; i < n; i++) {
        num[i] = numa[i] + numb[i];
    }

    // 当某一位上的数字>=10时, 进位, 否则截断
    for (int i = 0; i < n; i++) {
        if (num[i] >= 10) {
            num[i + 1] = num[i + 1] + num[i] / 10;
            num[i] = num[i] % 10;
        }
    }

    // 如果最后一位有进位, 则结果位数+1
    if (num[n] != 0) {
        n++;
    }

    // 逆序输出num, 既为答案
    for (int i = n - 1; i >= 0; i--) {
        cout << num[i];
    }

    return 0;
}