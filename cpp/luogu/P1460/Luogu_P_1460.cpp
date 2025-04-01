// https://www.luogu.com.cn/problem/P1460
// 二进制枚举(指数型枚举) 而不是组合型枚举.
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int v;          // 维他命种类数v
int minv[N];    // 维他命最小量
int g;          // 喂牛的饲料种数
int numv[N][N]; // 编号为n饲料包包含的各种维他命数量的多少
bool st[N];     // 此时是否选改饲料
int arr[N];     // 此时的总维生素
int mincnt = 1e9;
bool minst[N]; // 取的饲料编号
int flag = 0;

bool check() {
    for (int i = 1; i <= v; i++) {
        if (arr[i] < minv[i]) {
            return false;
        }
    }

    return true;
}
void dfs(int x, int cnt) { // 从第x位开始,选了cnt个
    if (x > g) {
        if (check()) {
            if (mincnt > cnt) {
                mincnt = cnt;
                for (int i = 1; i <= g; i++) {
                    minst[i] = st[i];
                }
            }
        }
        return;
    }

    st[x] = true; // 选
    for (int i = 1; i <= v; i++) {
        arr[i] += numv[x][i];
    }
    dfs(x + 1, cnt + 1);

    st[x] = false; // 回溯
    for (int i = 1; i <= v; i++) {
        arr[i] -= numv[x][i];
    }

    st[x] = false; // 不选
    dfs(x + 1, cnt);
}
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

    dfs(1, 0);

    cout << mincnt << " ";
    for (int i = 1; i <= g; i++) {
        if (minst[i] == true) {
            cout << i << " ";
        }
    }

    return 0;
}