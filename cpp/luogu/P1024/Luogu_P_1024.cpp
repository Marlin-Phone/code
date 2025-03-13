// https://luogu.com.cn/problem/P1024
#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;
int s;

double f(double x) { return a * x * x * x + b * x * x + c * x + d; }
int main() {
    cin >> a >> b >> c >> d;

    double l = -101, r = 101;
    for (double i = -101; i <= 101; i++) {
        double l = i, r = i + 1;
        if (f(l) == 0) { // 端点处
            printf("%.2lf ", i);
            s++;
        }
        if (f(l) * f(r) < 0) { // 区间内
            while (r - l > 1e-7) {
                double mid = (l + r) / 2;
                if (f(l) * f(mid) > 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            printf("%.2lf ", l);
            s++;
        }
        if (s == 3)
            break;
    }

    return 0;
}