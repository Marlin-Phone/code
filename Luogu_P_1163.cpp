// https://www.luogu.com.cn/problem/P1163
#include <bits/stdc++.h>
using namespace std;

double w0;    // w0 贷款的原值(未还款的金额)
double w;     // w 每月支付的分期付款金额
double m;     // m 分期付款还清贷款所需的总月数
double lilv;  // lilv  贷款的月利率
double w1;    // 未还款金额
double lirun; // 利润
double sum;

bool check(double x) {
    double w1 = w0;
    double m0 = m;
    double sum = w0;
    while (m0--) {
        lirun = w1 * 0.01 * x;
        w1 = w1 + lirun - w;
        sum += lirun;
    }
    // cout << "sum = " << sum << endl;
    if (sum - (w * m) < 0) { // 贷款还完了->利率低了,修改l
        return true;
    } else { // 贷款没还完->利率高了,修改r
        return false;
    }
}
int main() {
    cin >> w0 >> w >> m;

    // cout << "text" << endl;
    double l = 0, r = 600;
    while (r - l > 1e-4) {
        // cout << "l = " << l << " r = " << r << endl;
        double mid = (l + r) / 2;
        if (check(mid)) {
            // cout << "mid = " << mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    printf("%.1lf", l);

    // for (lilv = 0; lilv <= 300; lilv += 0.00001) {
    //     double w1 = w0;
    //     double m0 = m;
    //     double sum = w0;
    //     while (m0--) {
    //         lirun = w1 * 0.01 * lilv;
    //         w1 = w1 + lirun - w;
    //         sum += lirun;
    //     }
    //     // cout << "sum = " << sum << " w1 =" << w1 << endl;
    //     if (abs(sum - (w * m)) < 1) {
    //         break;
    //     }
    // }

    // printf("%.1lf", lilv);

    return 0;
}