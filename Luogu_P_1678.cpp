#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 10;
ll m;             // m 学校数
ll n;             // n 学生数
ll sch_scores[N]; // 第 i 个学校的预计录取分数
ll stu_scores[N]; // 第 i 个学生的估分成绩

bool check(ll x, ll score, ll &sch_scores) { // x 为位置, score为分数
    if (score) {                             // 学生成绩 < 学校成绩 , 则修改l
        return true;
    } else { // 学生成绩 >= 学校成绩, 则修改r
        return false;
    }
}
int main() {
    cin >> m >> n;
    for (ll i = 1; i <= m; i++) {
        cin >> sch_scores[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> stu_scores[i];
    }
    sort(sch_scores + 1, sch_scores + 1 + m);

    // for (auto it = begin(sch_scores) + 1; it != begin(sch_scores) + 1 + m;
    //      it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= m; i++) {
    //     cout << sch_scores[i] << " ";
    // }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        // ll l = 0, r = m + 1;
        // while (l + 1 != r) {
        //     ll mid = (l + r) / 2;
        //     if (check()) {
        //         l = mid;
        //     } else {
        //         r = mid;
        //     }
        // }
        int r = lower_bound(sch_scores + 1, sch_scores + 1 + m, stu_scores[i]) -
                sch_scores;
        int l = lower_bound(sch_scores + 1, sch_scores + 1 + m, stu_scores[i]) -
                sch_scores - 1;

        if (r == m + 1) {
            sum += abs(stu_scores[i] - sch_scores[l]);
        } else if (l == 0) {
            sum += abs(stu_scores[i] - sch_scores[r]);
        } else {
            sum += min(abs(stu_scores[i] - sch_scores[l]),
                       abs(stu_scores[i] - sch_scores[r]));
        }
    }

    cout << sum;

    return 0;
}