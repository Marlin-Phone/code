#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T; // 输入组数
    while (T--) {
        int n;
        cin >> n; // 输入天数
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // 输入币价
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i]; // 输入收入
        }

        long long totalCoins = 0; // 总的游戏币
        // 计算每天获得的游戏币
        for (int i = 0; i < n; i++) {
            totalCoins += (long long)b[i] * a[i]; // 将收入转化为获得的游戏币
        }

        // 二分搜索最大局数
        long long left = 0, right = totalCoins; // 最大局数不超过总币数
        while (left < right) {
            long long mid = (left + right + 1) / 2; // 中间值
            long long requiredCoins = 0;            // 当前局数需要的总币数

            // 计算当前局数需要多少游戏币
            for (int i = 0; i < n; i++) {
                requiredCoins += (mid + a[i] - 1) / a[i]; // 需要的币数
            }

            if (requiredCoins <= totalCoins) { // 如果总币数足够
                left = mid;                    // 尝试更大的局数
            } else {
                right = mid - 1; // 尝试更小的局数
            }
        }

        cout << left << endl; // 输出结果
    }
    return 0;
}
