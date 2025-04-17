/*
  @pintia psid=994805046380707840 pid=994805080346181632 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 倒数第N个字符串
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805080346181632
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int l, n;
string ans;

int main() {
    cin >> l >> n;
    int temp1 = l % 26;
    temp1++;
    char ansch = 'z' - temp1;
    return 0;
}
// @pintia code=end