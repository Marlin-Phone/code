// https://www.luogu.com.cn/problem/P1068
#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int n, m;
struct pep {
    int k;
    int s;
} pep[N];

bool cmp(const struct pep &a, const struct pep &b) {
    if (a.s != b.s) {
        return a.s > b.s;
    }
    return a.k < b.k;
}
int main() {
    cin >> n >> m;
    int m0 = m * 1.5 / 1;
    for (int i = 1; i <= n; i++) {
        cin >> pep[i].k >> pep[i].s;
    }

    sort(pep + 1, pep + 1 + n, cmp);

    int score = pep[m0].s;

    int i;
    for (i = 1; i <= n; i++) {
        if (pep[i].s < score) {
            i--;
            break;
        }
    }

    cout << score << " " << i << endl;
    // cout << i;
    for (int j = 1; j <= i; j++) {
        cout << pep[j].k << " " << pep[j].s << endl;
    }

    return 0;
}