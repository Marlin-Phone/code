/*
  @pintia psid=994805046380707840 pid=994805071789801472 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 月饼
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805071789801472
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, d;
int liang[N], sold[N];
double v[N];
struct node {
    double liang;
    double sold;
    double v;

} node[N];
double ans = 0;

bool cmp(struct node &a, struct node &b) { return a.v > b.v; }
int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].liang;
    }
    for (int i = 1; i <= n; i++) {
        cin >> node[i].sold;
        node[i].v = 1.0 * node[i].sold / node[i].liang;
    }
    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        if (d - node[i].liang > 0) {
            d -= node[i].liang;
            ans += node[i].sold;
        } else {
            ans += node[i].v * d;
            break;
        }
    }
    printf("%.2lf", ans);

    return 0;
}
// @pintia code=end