#include <bits/stdc++.h>
using namespace std;

int T;
long long x0, k;
long long num;
long long minnum = 1e18;
long long arr[100];
int cnt = 0;

long long getnum(int l, int r) {
    num = 0;
    for (int i = l; i <= r; i++) {
        num = num * 2 + arr[i];
    }
    // cout << "num = " << num << endl;
    return num;
}
void dfs(int x) {  // 第x位
    if (cnt > k) { // 剪枝
        return;
    }
    if (cnt == k) {
        num = abs(getnum(1, 60) - x0);
        minnum = min(num, minnum);
        return;
    }
    if (x > 60) {
        return;
    }

    int remaining = 60 - x + 1;
    if (cnt + remaining < k) {
        return;
    }

    arr[x] = 1; // 选
    cnt++;
    dfs(x + 1);

    arr[x] = 0; // 回溯
    cnt--;

    arr[x] = 0; // 不选

    dfs(x + 1);
}
int main() {
    cin >> T;
    while (T--) {
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        minnum = 1e18;
        cin >> x0 >> k;
        // cout << "text";
        dfs(1);
        // cout << "text";
        cout << minnum << endl;
    }

    return 0;
}