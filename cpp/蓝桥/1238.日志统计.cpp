/*
 * @acwing app=acwing.cn id=1240 lang=C++
 *
 * 1238. 日志统计
 */

// @acwing code start
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, d, k;
pair<int, int> logs[N];
int cnt[N];
int st[N];

int main() {
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        cin >> logs[i].first >> logs[i].second;
    }

    sort(logs, logs + n);

    int l = 0, r = 0;
    while (r < n) {
        // i为右指针 j为左指针
        int id = logs[r].second;
        cnt[id]++;

        while (logs[r].first - logs[l].first >= d) {
            cnt[logs[l].second]--;
            l++;
        }

        if (cnt[id] >= k) {
            st[id] = 1;
        }
        r++;
    }

    for (int i = 0; i <= 100000; i++) {
        if (st[i]) {
            cout << i << endl;
        }
    }

    return 0;
}

// @acwing code end