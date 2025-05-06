#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int arr[N];
int help[N];

int smallSum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}
int merge(int l, int m, int r) {
    // 统计部分
    int ans = 0;
    for (int i = l, j = m + 1, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }
    // 正常marge
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        if (arr[a] <= arr[b]) {
            help[i++] = arr[a++];
        } else {
            help[i++] = arr[b++];
        }
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }

    return ans;
}
void smallmerge(int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    smallmerge(l, m);
    smallmerge(m + 1, r);
    merge(l, m, r);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    smallSum(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}