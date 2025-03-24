// https://www.luogu.com.cn/problem/P1996
// 队列模拟约瑟夫环问题
#include <bits/stdc++.h>
using namespace std;

int n, m; // n个人 数到m的人出圈
queue<int> que;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }

    int cnt = 0;
    while (!que.empty()) {
        cnt++;
        if (cnt == m) {
            cout << que.front() << " ";
            que.pop();
            cnt = 0;
        } else {
            que.push(que.front());
            que.pop();
        }
    }

    return 0;
}