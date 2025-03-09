// https://www.luogu.com.cn/contest/198710
// 80分
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e4 + 10;
int T;       // 数据组数
long long m; // 序列中元素的和
int cnt = 0;
vector<long long> arr(N);
int flag = 0;

bool cnt_flag(int x) {
    int i = 1;
    while (i <= x) {
        i = i * 2;
    }
    i = i / 2;
    if (i == x) {
        return true;
    }
    return false;
}
long long getnum(int x) {
    int i = 1;
    while (i <= x) {
        i = i * 2;
    }
    return i / 2;
}
void dfs(long long x) {
    if (x == 0) {
        if (cnt_flag(cnt)) {
            flag = 1;
            sort(arr.begin() + 1, arr.begin() + 1 + cnt);
            for (int i = 1; i <= cnt; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (long long i = getnum(x); i > 0 && flag == 0; i /= 2) {
        cnt++;
        arr[cnt] = i;
        dfs(x - i);
        arr[cnt] = 0; // 回溯
        cnt--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> m;
        flag = 0;
        dfs(m);
    }

    return 0;
}