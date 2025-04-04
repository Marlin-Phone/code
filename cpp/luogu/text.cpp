// 求2的n次方
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n;
int ans[N];
int index;

void cheng() {
    int carry = 0;
    for (int i = 1; i <= N - 10; i++) {
        int product = ans[i] * 2 + carry;
        ans[i] = product % 10;
        carry = product / 10;

        // cout << "ans[" << i << "]" << " = " << ans[i] << endl;
    }
    // index = N - 10;
    // while (ans[index] == 0 && index > 1)
    //     index--;

    // for (int i = index; i >= 1; i--) {
    //     cout << ans[i];
    // }
    // cout << endl;
}
int main() {
    cin >> n;
    ans[1] = 1;
    for (int i = 1; i <= n; i++) {
        cheng();
    }

    index = N - 10;
    while (ans[index] == 0 && index > 1)
        index--;

    for (int i = index; i >= 1; i--) {
        cout << ans[i];
    }

    return 0;
}