#include <bits/stdc++.h>
using namespace std;

int num;
int st[15];
int arr[15];
int ans;

// 将数组中的一段转换为整数
int calculate(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        res = res * 10 + arr[i];
    }
    return res;
}

void dfs(int x) {
    if (x > 9) {
        for (int i = 1; i <= 7; i++) {
            int a = calculate(1, i);
            for (int j = i + 1; j <= 8 - i; j++) {
                int b = calculate(i + 1, j);
                int c = calculate(j + 1, 9);
                if (b % c == 0 && a + b / c == num) {
                    ans++;
                }
            }
        }
        // cout << endl;
    }
    for (int i = 1; i <= 9; i++) {
        if (st[i] == true) {
            continue;
        }
        st[i] = 1;
        arr[x] = i;
        dfs(x + 1);
        st[i] = 0;
        arr[x] = 0;
    }
}
int main() {
    cin >> num;
    dfs(1);
    cout << ans;
    return 0;
}