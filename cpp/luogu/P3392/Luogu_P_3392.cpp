// https://www.luogu.com.cn/problem/P3392
#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[60][60];
int ans_W[60]; // 每行变成W需要的修改次数
int ans_B[60]; // 每行变成B需要的修改次数
int ans_R[60]; // 每行变成R需要的修改次数

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    // 预处理每行的三种颜色修改次数
    for (int i = 1; i <= n; i++) {
        int cntW = 0, cntB = 0, cntR = 0;
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != 'W')
                cntW++;
            if (g[i][j] != 'B')
                cntB++;
            if (g[i][j] != 'R')
                cntR++;
        }
        ans_W[i] = cntW;
        ans_B[i] = cntB;
        ans_R[i] = cntR;
    }

    // 计算前缀和
    int sum_W[60] = {0}, sum_B[60] = {0}, sum_R[60] = {0};
    for (int i = 1; i <= n; i++) {
        sum_W[i] = sum_W[i - 1] + ans_W[i];
        sum_B[i] = sum_B[i - 1] + ans_B[i];
        sum_R[i] = sum_R[i - 1] + ans_R[i];
    }

    int ans = 1e9; // 初始化为一个大值
    // 枚举白色结束行i和蓝色结束行j
    for (int i = 1; i <= n - 2; i++) { // 白色至少1行，剩余至少2行（蓝、红各1）
        for (int j = i + 1; j <= n - 1; j++) { // 蓝色至少1行，红色至少1行
            int total = sum_W[i] + (sum_B[j] - sum_B[i]) +
                        (sum_R[n] - sum_R[j]); // 前缀和计算
            if (total < ans) {
                ans = total;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
