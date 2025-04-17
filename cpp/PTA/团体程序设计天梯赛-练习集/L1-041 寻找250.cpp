/*
  @pintia psid=994805046380707840 pid=994805089657536512 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 寻找250
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805089657536512
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int num;
int cnt = 0;

int main() {
    while (1) {
        cin >> num;
        cnt++;
        if (num == 250) {
            // cnt++;
            cout << cnt;
            break;
        }
    }

    return 0;
}
// @pintia code=end