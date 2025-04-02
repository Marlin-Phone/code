// https://www.luogu.com.cn/problem/P1478
#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int n, s;       // 苹果数n 力气s
int a, b;       // 椅子高a 个子高b
int x[N], y[N]; // 苹果高度xi 苹果需要的力气yi
struct apple {
    int flag = 1; // 默认能够到
    int height;
    int liqi;
} apple[N];
int ans = 0;

bool cmp(struct apple &a, struct apple &b) { return a.liqi < b.liqi; }
int main() {
    cin >> n >> s;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> apple[i].height >> apple[i].liqi;
        if (apple[i].height > a + b) { // 如果够不到
            apple[i].flag = 0;
        }
    }

    sort(apple + 1, apple + 1 + n, cmp);

    for (int i = 1; i <= n && s > 0; i++) {
        if (apple[i].flag == 0) {
            continue;
        }
        s -= apple[i].liqi;
        if (s >= 0) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}