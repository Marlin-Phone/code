#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int temp[N] = {1};
int ans[N] = {0};

void aplusb(int ans[], int temp[]) { // 高精度 + 高精度
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        }
    }
}
void atimesb(int temp[], int j) { // 高精度 * 单精度
    for (int i = 0; i < N; i++) { // N 不够对
        temp[i] *= j;
        if (temp[i] > 9) {
            temp[i + 1] += temp[i] / 10;
            temp[i] = temp[i] % 10;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        temp[0] = 1;
        for (int j = 1; j <= i; j++) {
            // temp *= j;
            atimesb(temp, j);
        }
        // ans += temp;
        aplusb(ans, temp);
    }

    cout << ans;

    return 0;
}