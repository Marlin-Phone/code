// https://www.luogu.com.cn/problem/P1563
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n; // n个小人
int m; // m条指令
struct pep {
    int flag;
    string str;
} pep[N];
int a, s;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        // -1:向内 1:向外
        cin >> pep[i].flag >> pep[i].str;
        if (pep[i].flag == 0) {
            pep[i].flag = -1;
        }
    }

    int i = 1;
    while (m--) {
        // 指令1为左数,-1为右数 s个人.
        cin >> a >> s;
        if (a == 0) {
            a = 1;
        } else if (a == 1) {
            a = -1;
        }

        if (a * pep[i].flag == 1) { // +
            i += s;
        } else if (a * pep[i].flag == -1) { // -
            i -= s;
        }
        i = (i % n + n) % n;
        if (i == 0) {
            i = n;
        }
    }

    cout << pep[i].str << endl;

    return 0;
}