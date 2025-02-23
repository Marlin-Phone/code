#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int T;       // 数据组数
long long m; // 序列中元素的和

int getnum(int x) {
    int i = 1;
    while (i <= x) {
        i = i * 2;
    }
    return i / 2;
}
bool cnt_flag(int x) {
    int i = 1;
    while (i <= x) {
        i = i * 2;
    }
    i = i / 2;
    if (i == x) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << getnum(n) << endl;
    cout << cnt_flag(n) << endl;
    return 0;
}