// https://www.luogu.com.cn/problem/P1208
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 10;
int need_milk, m; // 需要牛奶的总量 提供牛奶的农民个数
struct farmer {
    int mik_val; // 牛奶单价
    int mik_num; // 牛奶量
} farmer[N];
int money = 0;

bool cmp(struct farmer &a, struct farmer &b) { return a.mik_val < b.mik_val; }
signed main() {
    cin >> need_milk >> m;
    for (int i = 1; i <= m; i++) {
        cin >> farmer[i].mik_val >> farmer[i].mik_num;
    }

    sort(farmer + 1, farmer + 1 + m, cmp);

    // for (int i = 1; i <= m; i++) {
    //     cout << farmer[i].mik_val << " ";
    // }

    int i = 1;
    while (need_milk > 0 && i <= m) {
        if (need_milk - farmer[i].mik_num >= 0) {
            need_milk -= farmer[i].mik_num;
            money += farmer[i].mik_val * farmer[i].mik_num;
        } else {
            money += farmer[i].mik_val * need_milk;
            need_milk = 0;
        }
        // cout << "money = " << money << endl;
        i++;
    }

    cout << money;

    return 0;
}