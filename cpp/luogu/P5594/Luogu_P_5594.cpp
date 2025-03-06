#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int main() {
    int n, m, k;
    int free;
    int day[N] = {0};

    cin >> n >> m >> k;
    vector<vector<int>> freeday(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> freeday[i][j];
        }
    }

    for (int j = 0; j < m; j++) { // free为第free天有时间
        int flag[N] = {0};
        for (int i = 0; i < n; i++) {
            if (flag[freeday[i][j] - 1] == 0) {
                day[freeday[i][j] - 1]++;
                flag[freeday[i][j] - 1] = 1;
            }
        }
    }

    for (int i = 0; i < k; i++) { // 最终输出前k天出题数目
        cout << day[i] << ' ';
    }

    return 0;
}