// https://www.luogu.com.cn/problem/P1149
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 1e4 + 10;
int n;
int nums[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int arr[N];
int res = 0;

// 计算前1000个火柴棍的数量
void getnums() {
    for (int j = 10; j <= 1000; j++) {
        int j0 = j;
        while (j0) {
            nums[j] = nums[j] + nums[j0 % 10];
            j0 = j0 / 10;
        }
    }
}
// int col(int i) {
//     if (nums[i]) {
//         return nums[i];
//     } else {
//         int sumFire = 0;
//         while (i) {
//             sumFire += nums[i % 10];
//             i /= 10;
//         }
//         return sumFire;
//     }
// }

void dfs(int x, int sum) {
    if (sum > n) { // 剪枝
        return;
    }
    if (x > 3) {
        if (arr[1] + arr[2] == arr[3] && sum == n) {
            res++;
        }
        return;
    }

    for (int i = 0; i <= 1000; i++) {
        arr[x] = i;
        dfs(x + 1, sum + nums[i]);
        arr[x] = 0;
    }
}
int main() {
    IOS;
    for (int i = 10; i <= 1000; i++) { // 计算前1000个火柴棍 递推优化
        nums[i] = nums[i % 10] + nums[i / 10];
    }
    cin >> n;
    n = n - 4;
    dfs(1, 0);
    cout << res << endl;
    return 0;
}