#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1;
    int b = ~a + 1;
    int c = INT_MIN;
    // 输出c的二进制
    cout << bitset<32>(INT_MIN) << endl;
    int d = ~c + 1;
    cout << ~c << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // 0b指二进制----------------------------------------
    cout << "0b指二进制,0x指十六进制,0/"
            "o指的是八进制----------------------------------------"
         << endl;

    int g = 0b0001010;
    int h = 0b0001100;
    cout << (g | h) << endl;
    cout << 0b0001110 << endl;

    printf("%o\n", 12); // 八进制,输出14
    printf("%x\n", 12); // 十六进制,输出c

    // 左移右移---------------------------------------------------------
    cout << "左移右移-------------------------------------------------" << endl;
    int e = 0b00000001;
    int f = 0b00000001;
    int i = -000000001; // -1
    cout << "e = " << e << endl;
    cout << 256 * 16 << endl;
    cout << (e << 4) << endl;
    cout << 0b00010000 << endl;
    cout << (e >> 4) << endl;

    return 0;
}