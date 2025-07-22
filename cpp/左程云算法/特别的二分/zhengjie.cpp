#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int> &a) {
    if (a[mid - 1] > a[mid]) {
        return true;
    } else {
        return false;
    }
}

int solution(vector<int> &a) {
    int n = a.size();
    if (n == 1) {
        return 0;
    }
    if (a[0] > a[1]) {
        return 0;
    }
    if (a[n - 2] < a[n - 1]) {
        return n - 1;
    }

    int l = 1, r = n - 2, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
            return mid;
        }
        // 决定搜索方向
        else if (a[mid] < a[mid + 1]) {
            l = mid + 1; // 峰值在右侧
        } else {
            r = mid - 1; // 峰值在左侧
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solution(a);

    return 0;
}