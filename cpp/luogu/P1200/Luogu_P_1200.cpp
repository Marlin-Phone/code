// https://www.luogu.com.cn/problem/P1200
#include <bits/stdc++.h>
using namespace std;

string star_name;
string que_name;
int star_num = 1;
int que_num = 1;

int main() {
    cin >> star_name >> que_name;
    for (int i = 0; i < star_name.size(); i++) {
        star_num *= star_name[i] - 'A' + 1;
    }
    // cout << star_num << endl;
    star_num %= 47;
    // cout << star_num << endl;
    for (int i = 0; i < que_name.size(); i++) {
        que_num *= que_name[i] - 'A' + 1;
    }
    // cout << que_num << endl;
    que_num %= 47;
    // cout << que_num << endl;
    if (star_num == que_num) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }

    return 0;
}