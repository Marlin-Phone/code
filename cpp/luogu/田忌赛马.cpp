// https://ac.nowcoder.com/acm/contest/102742/A
#include <bits/stdc++.h>
using namespace std;

int v[4], a[4];
int arr[4];
int win_time = 0;
bool flag = false;
bool st[4];

void dfs(int x) { // x 表示当前的位置
    if (flag == true) {
        return;
    }
    if (x > 3) {
        win_time = 0;
        for (int i = 1; i <= 3; i++) {
            if (arr[i] > v[i]) {
                // cout << arr[i] << " " << v[i] << endl;
                win_time++;
            }
        }
        if (win_time >= 2) {
            flag = true;
            cout << "Yes";
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (st[i] == true) {
            continue;
        }
        arr[x] = a[i];
        st[i] = true;
        dfs(x + 1);
        arr[x] = 0; // 回溯
        st[i] = false;
    }
}

int main() {
    for (int i = 1; i <= 3; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= 3; i++) {
        cin >> a[i];
    }

    dfs(1);

    if (flag == false) {
        cout << "No";
    }

    return 0;
}