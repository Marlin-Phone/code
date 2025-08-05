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
int buffer[10];
int cnt[10];

const int BASE = 10; // BASE进制下
// 计算整数x的位数
int getBits(int x) {
    int res = 0;
    while (x != 0) {
        x /= BASE;
        res++;
    }
    return res;
}
// 前提：arr中的元素都是BASE进制下的非负整数
void radixSort(vector<int> &arr, int bits) { // bits是arr中最大值在BASE下有几位
    int n = arr.size();
    vector<int> help(arr.size(), 0);
    for (int offset = 1; bits > 0; offset *= BASE, bits--) {
        vector<int> cnts(10, 0); // cnts用来做词频统计
        for (int i = 0; i < arr.size(); i++) {
            cnts[(arr[i] / offset) % 10]++; // 提取某一位的词频
        }
        for (int i = 1; i < BASE; i++) {
            cnts[i] = cnts[i] + cnts[i - 1]; // 处理成前缀次数累加的形式
        }
        for (int i = n - 1; i >= 0; i--) {
            // 前缀分区的技巧
            help[--cnts[(arr[i] / offset) % BASE]] = arr[i]; //
        }
        for (int i = 0; i < n; i++) {
            arr[i] = help[i];
        }
    }
}
// 基数排序（可包含负数）
void sortArray(vector<int> &arr) {
    int n = arr.size();
    int minnum = INT_MAX;
    for (int i = 0; i < n; i++) {
        minnum = min(minnum, arr[i]);
    }
    int maxnum = INT_MIN;
    for (int i = 0; i < n; i++) {
        arr[i] -= minnum;
        maxnum = max(maxnum, arr[i]);
    }
    radixSort(arr, getBits(maxnum));
    for (int i = 0; i < n; i++) {
        arr[i] += minnum;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sortArray(arr);
    for (auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
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