#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int ans[N] = {1};

void atimesb(int ans[], int b) {
    int carry = 0;
    for (int i = 0; i < N; i++) {
        int product = ans[i] * b + carry;
        ans[i] = product % 10;
        carry = product / 10;
    }
}
int main() {
    // cin >> n;
    cout << pow(2, 100) << endl;
    for (int i = 1; i <= 100; i++) {
        atimesb(ans, 2);
    }

    int index;
    for (int i = 99; i >= 0; i--) {
        if (ans[i] != 0) {
            index = i;
            break;
        }
    }

    for (int i = index; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}