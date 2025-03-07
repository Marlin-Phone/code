// https://www.luogu.com.cn/problem/P1765
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int N = 210;
char ch;
int count = 0;

int main() {

    while (cin.get(ch)) {
        if (ch == '\0')
            break;
        if (ch == ' ')
            count++;
        if (ch == 'a' || ch == 'd' || ch == 'g' || ch == 'j' || ch == 'm' ||
            ch == 'p' || ch == 't' || ch == 'w')
            count++;
        if (ch == 'b' || ch == 'e' || ch == 'h' || ch == 'k' || ch == 'n' ||
            ch == 'q' || ch == 'u' || ch == 'x')
            count += 2;
        if (ch == 'c' || ch == 'f' || ch == 'i' || ch == 'l' || ch == 'o' ||
            ch == 'r' || ch == 'v' || ch == 'y')
            count += 3;
        if (ch == 's' || ch == 'z')
            count += 4;
    }

    cout << count;

    return 0;
}