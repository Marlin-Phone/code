// https://www.luogu.com.cn/problem/P5015
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n, count = 0;

    getline(cin, s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            continue;
        }
        count++;
    }

    cout << count;

    return 0;
}