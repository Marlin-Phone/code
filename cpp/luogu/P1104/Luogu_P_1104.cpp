// https://www.luogu.com.cn/problem/P1104
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
struct data {
    string s;
    int y;
    int m;
    int d;
    int num;
} data[N];

bool cmp(const struct data &a, const struct data &b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    if (a.m != b.m) {
        return a.m < b.m;
    }
    if (a.d != b.d) {
        return a.d < b.d;
    }
    return a.num > b.num;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> data[i].s >> data[i].y >> data[i].m >> data[i].d;
        data[i].num = i;
    }
    sort(data + 1, data + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        cout << data[i].s << endl;
    }

    return 0;
}