// https://www.luogu.com.cn/problem/P2404
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
int arr[N];
int arrsum;

void dfs(int x) { // x 表示当前的位数
    if (arrsum >= n) {
        if (arrsum == n) {
            int flag = 1;
            for (int i = 1; i <= n && arr[i] != 0; i++) {
                if (arr[i - 1] > arr[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                for (int i = 1; arr[i] != 0; i++) {
                    cout << arr[i];
                    if (arr[i + 1] != 0) {
                        cout << "+";
                    }
                }
                cout << endl;
            }
        }

        return;
    }

    for (int i = 1; i < n; i++) {
        arr[x] = i;
        arrsum += i;
        dfs(x + 1);
        arr[x] = 0; // 回溯
        arrsum -= i;
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}