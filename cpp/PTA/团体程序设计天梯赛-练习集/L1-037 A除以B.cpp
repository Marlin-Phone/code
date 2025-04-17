/*
  @pintia psid=994805046380707840 pid=994805094485180416 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: A除以B
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805094485180416
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    double c = 1.0 * a / b;

    if (b < 0) {
        printf("%d/(%d)=%.2lf", a, b, c);
    } else if (b == 0) {
        printf("%d/%d=Error", a, b);
    } else {
        printf("%d/%d=%.2lf", a, b, c);
    }

    return 0;
}
// @pintia code=end