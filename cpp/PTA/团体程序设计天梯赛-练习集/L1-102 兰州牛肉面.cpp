/*
  @pintia psid=994805046380707840 pid=1781658570803388421 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 兰州牛肉面
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388421
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
double price[N];
int cnt[N];
int idx, thiscnt;
double ans;
int flag;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    cin >> idx >> thiscnt;
    while (idx != 0 && thiscnt != 0) {
        cnt[idx] += thiscnt;
        ans += thiscnt * price[idx];

        cin >> idx >> thiscnt;
    }

    for (int i = 1; i <= n; i++) {
        if (flag)
            cout << endl;
        flag = 1;
        cout << cnt[i];
    }
    cout << endl;
    printf("%.2lf", ans);

    return 0;
}
// @pintia code=end