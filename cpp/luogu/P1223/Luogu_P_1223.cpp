// https://www.lougu.com.cn/problem/P1223
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int T[N];
double t_total = 0;
struct node {
    int index;
    int t;
} node[N];

bool cmp(struct node &a, struct node &b) { return a.t < b.t; }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].t;
        node[i].index = i;
    }

    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        cout << node[i].index << " ";
        t_total += node[i].t * (n - i);
    }
    cout << endl;
    printf("%.2lf", t_total / n);

    return 0;
}