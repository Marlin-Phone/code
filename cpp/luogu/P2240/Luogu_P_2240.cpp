// https://www.luogu.com.cn/problem/P2240
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int m[N], v[N];
double temp[N];
double t0, t; // t0当前容量 t背包容量
double v0;    // v0当前价值
struct node {
    int m, v;
    double temp;
} node[N];

bool cmp(struct node &a, struct node &b) { return a.temp > b.temp; }
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].m >> node[i].v;
        node[i].temp = 1.0 * node[i].v / node[i].m;
    }

    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        if (t0 + node[i].m >= t) { // 背包装满了
            v0 += node[i].temp * (t - t0);
            t0 = t;
            break;
        } else {
            v0 += node[i].v;
            t0 += node[i].m;
        }
    }

    printf("%.2lf", v0);

    return 0;
}