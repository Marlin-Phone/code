/*
  @pintia psid=994805046380707840 pid=1781658570803388419 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 四项全能
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388419
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, total = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        total += k;
    }
    int result = max(0, total - n * (m - 1));
    cout << result;
    return 0;
}

// @pintia code=end