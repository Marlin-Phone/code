#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        cout << ((num & (1L << i)) == 0 ? 0 : 1);
    }
    cout << endl;
}
int main() {
    // int num = 1;
    // for (int i = 1; i <= (1 << 6); i++) {
    //     printBinary(i);
    // }
    // cout << endl;

    cout << (1LL << 31) << endl;
    cout << (1LL << 63) << endl;
}