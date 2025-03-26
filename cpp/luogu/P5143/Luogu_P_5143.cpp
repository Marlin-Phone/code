// https://www.luogu.com.cn/problem/P5143
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int n;
double length = 0;
struct xyz {
    int x;
    int y;
    int z;
} xyz[N];

bool cmp(struct xyz &a, struct xyz &b) { return a.z < b.z; }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xyz[i].x >> xyz[i].y >> xyz[i].z;
    }

    sort(xyz + 1, xyz + 1 + n, cmp);

    for (int i = 2; i <= n; i++) {
        int x = xyz[i].x - xyz[i - 1].x;
        int y = xyz[i].y - xyz[i - 1].y;
        int z = xyz[i].z - xyz[i - 1].z;
        length += sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    printf("%.3lf", length);

    return 0;
}