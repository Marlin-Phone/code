// 二进制枚举(指数型枚举) 而不是组合型枚举.
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int v;          // 维他命种类数v
int minv[N];    // 维他命最小量
int g;          // 喂牛的饲料种数
int numv[N][N]; // 编号为n饲料包包含的各种维他命数量的多少
int arr[N];
int arrv[N];
int flag[N];
int minx = 1e9;
int minarr[N];

void dfs(int x, int s) {}
int main() {
    cin >> v;
    for (int i = 1; i <= v; i++) {
        cin >> minv[i];
    }
    cin >> g;
    for (int i = 1; i <= g; i++) {
        for (int j = 1; j <= v; j++) {
            cin >> numv[i][j];
        }
    }

    return 0;
}