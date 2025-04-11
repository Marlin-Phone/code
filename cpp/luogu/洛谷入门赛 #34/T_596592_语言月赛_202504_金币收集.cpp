// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e5 + 10;
int n, s, m; // 区域个数 起点 移动次数
int mov[N] = {0};
vector<vector<int>> p(1010);
int ans = 0;
int nowway;
int cnt[1010] = {0};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> m;
    for (int i = 1; i <= m; i++) { // 移动
        cin >> mov[i];
    }

    // cout << "text" << endl;

    for (int i = 1; i <= n; i++) { // 区域i
        int temp;
        cin >> temp;
        p[i].push_back(temp);
        for (int j = 1; j <= p[i][0]; j++) { // 可获得奖励次数 p[i][j];
            int temp;
            cin >> temp;
            p[i].push_back(temp);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= p[i][0]; j++) {
    //         cout << p[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    nowway = s;
    if (cnt[nowway] >= 1) {
        ans += p[nowway][1];
    }
    cnt[nowway]++;
    // cout << "text2" << endl;
    for (int i = 1; i <= m; i++) {
        if (mov[i] == 1) {
            nowway++;
            if (nowway == n + 1) {
                nowway = 1;
            }
        } else {
            nowway--;
            if (nowway == 0) {
                nowway = n;
            }
        }

        if (cnt[nowway] < p[nowway][0]) {
            cnt[nowway]++;
            ans += p[nowway][cnt[nowway]];
        }
    }

    cout << ans;

    return 0;
}