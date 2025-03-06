// https://www.luogu.com.cn/problem/P2010
#include <iostream>
using namespace std;
int main() {
    int ge, shi, bai, qian;
    int count = 0;
    int day, month;
    int data;
    int begin_data, end_data;
    int monthday[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> begin_data >> end_data;

    for (int month = 1; month <= 12; month++) {
        for (int day = 1; day <= monthday[month]; day++) {
            ge = day % 10;
            shi = day / 10;
            bai = month % 10;
            qian = month / 10;
            data = ge + shi * 10 + bai * 100 + qian * 1000 + qian * 1e4 +
                   bai * 1e5 + shi * 1e6 + ge * 1e7;
            if (begin_data <= data && data <= end_data) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}