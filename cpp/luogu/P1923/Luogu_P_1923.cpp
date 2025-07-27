// https://luogu.com.cn/problem/P1923
// 随机选择 随机快速排序 荷兰国旗
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 5e6 + 10;
int T = 1;
int n, k;
int nums[N];

int quickSelect(int l, int r) {
    if (l >= r) {
        return nums[l];
    }

    int x = l + rand() % (r - l + 1);
    int pivot = nums[x];

    int a = l;
    int b = r;
    int i = l;

    while (i <= b) {
        if (nums[i] < pivot) {
            swap(nums[i++], nums[a++]);
        } else if (nums[i] > pivot) {
            swap(nums[i], nums[b--]);
        } else {
            i++;
        }
    }

    if (k < a) {
        return quickSelect(l, a - 1);
    } else if (k > b) {
        return quickSelect(b + 1, r);
    } else {
        return pivot;
    }
}
void solve() {
    srand(time(0));
    cin >> n >> k;
    k++;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    cout << quickSelect(1, n);
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