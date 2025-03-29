// 闰年判断错误,&&写为了||
#include <bits/stdc++.h>
using namespace std;

int day = 0;

bool isrun(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return true; // 是闰年
    } else {
        return false; // 不是闰年
    }
}
int main() {
    // cout << 46 * 46 << endl;
    for (int i = 2025; i <= 2116 - 1; i++) {
        if (isrun(i)) {
            day += 366;
        } else {
            day += 365;
        }
    }

    // 减去2025年已经过的天数.
    day -= 31 + 28 + 28;
    cout << day;

    return 0;
}