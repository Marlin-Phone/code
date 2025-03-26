// https://www.luogu.com.cn/problem/P1093
#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int n;
struct Scores {
    int id;
    int yu, math, en;
    int tot;
} scores[N];

bool cmp(const Scores &a, const Scores &b) {
    if (a.tot != b.tot) {
        return a.tot > b.tot;
    }
    if (a.yu != b.yu) {
        return a.yu > b.yu;
    }
    return a.id < b.id;

    // if (a.tot > b.tot) {
    //     return true;
    // } else if (a.tot == b.tot) {
    //     if (a.yu > b.yu) {
    //         return true;
    //     } else if (a.yu == b.yu) {
    //         if (a.id < b.id)
    //             return true;
    //         else {
    //             return false;
    //         }
    //     } else {
    //         return false;
    //     }
    // } else {
    //     return false;
    // }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scores[i].id = i;
        cin >> scores[i].yu >> scores[i].math >> scores[i].en;
        scores[i].tot = scores[i].yu + scores[i].math + scores[i].en;
    }

    sort(scores + 1, scores + 1 + n, cmp);

    for (int i = 1; i <= 5; i++) {
        cout << scores[i].id << " " << scores[i].tot << endl;
    }

    return 0;
}