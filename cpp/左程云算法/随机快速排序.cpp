// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n;
int arr[N];

void quickSort1(int l, int r) {
    if (l >= r) {
        return;
    }
    int x = l + rand() % (r - l + 1);
    int pivot = arr[x];

    int i = l;       // 当前位置检查
    int a = l;       // 小于区域的右边界
    int b = r;       // 大于区域的左边界
    while (i <= b) { // 荷兰国旗问题优化 |<pivot|=piovt|>piovt
        if (arr[i] < pivot) {
            swap(arr[i++], arr[a++]);
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[b--]);
        } else {
            i++;
        }
    }

    quickSort1(l, a - 1);
    quickSort1(b + 1, r);
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort1(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}