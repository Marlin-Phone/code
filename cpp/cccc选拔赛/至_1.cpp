#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);
#define endl "\n"

double a[13], b[13], c[13];
double p[13];           // 解出来第i题的概率
double arr[13];         // 记录第i题是否选中
int ans = 0;            // 选中的题目数
double sum_p[13] = {0}; // 记录解出i题的概率和

void dfs(int x) {
    if (x > 12) {
        int cnt = 0;    // 选中的题目数归零
        double sum = 1; // 记录选中的题目概率和
        for (int i = 1; i <= 12; i++) {
            if (arr[i] != 0) {
                // cout << arr[i] << " ";
                cnt++;
                sum *= 1 - p[i];
            } else {
                sum *= p[i];
            }
        }
        // cout << "ans = " << ans << endl;
        // cout << "sum = " << sum << endl;

        sum_p[cnt] += sum;
        return;
    }

    arr[x] = 1; // 选第x题
    // cout << arr[x] << " ";
    dfs(x + 1);
    arr[x] = 0; // 回溯
    dfs(x + 1);
}
int main() {
    IOS;
    for (int i = 1; i <= 12; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 12; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= 12; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= 12; i++) {
        p[i] = (1 - a[i]) * (1 - b[i]) * (1 - c[i]);
        // cout << "p = " << p[i] << endl;
    }

    dfs(1); // 选或不选第x题;

    for (int i = 0; i <= 12; i++) {
        printf("%.6lf\n", sum_p[i]);
    }

    return 0;
}