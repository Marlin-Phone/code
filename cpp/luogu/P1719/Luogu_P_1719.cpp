// https://www.luogu.com.cn/problem/P1719
#include <iostream>
#include <vector>
using namespace std;

const int N = 130;
int n;
vector<vector<int>> nums(N, vector<int>(N)), sumnums(N, vector<int>(N));
vector<vector<int>> sumnums1(N, vector<int>(N));
int maxnum = -1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> nums[i][j];
        }
    }

    // 对每一行求前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sumnums[i][j] = sumnums[i][j - 1] + nums[i][j];
        }
    }
    // 对每一列求前缀和
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sumnums1[i][j] = sumnums1[i - 1][j] + sumnums[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i + 1; k <= n; k++) {
                for (int l = j + 1; l <= n; l++) {
                    maxnum = max(maxnum,
                                 sumnums1[k][l] + sumnums1[i - 1][j - 1] -
                                     sumnums1[k][j - 1] - sumnums1[i - 1][l]);
                }
            }
        }
    }

    cout << maxnum;

    return 0;
}