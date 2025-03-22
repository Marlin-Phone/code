#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, t;
int a[N], b[N];

bool check(long long tim0) {
    int day = 0;
    int i = 1;
    while (i <= n) {
        long long tim = tim0;
        if (a[i] > tim)
            return false; // 无法处理当前电脑
        tim -= a[i];
        i++;
        while (i <= n) {
            long long need = a[i] + b[i - 1]; // 需要a[i]和之前等待时间
            if (need > tim)
                break;
            tim -= need;
            i++;
        }
        day++;
        if (day > t)
            return false;
    }
    return day <= t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    long long left = 0, right = 1e18, ans = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << (ans != -1 ? ans : -1);
}
