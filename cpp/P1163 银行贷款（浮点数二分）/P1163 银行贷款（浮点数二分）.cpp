//https://www.luogu.com.cn/problem/P1163
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

double w0, w, m, x;

bool isblue(double mid) {
	double s = 0, t = 1;
	for (int i = 1; i <= m; i++) {
		t = t * (1 + mid);
		s = s + w / t;
	}
	cout << "s = " << s << "mid = "<< mid << endl;
	if (s > mid) return false;
	else return true;
}

int main() {
	double a;
	scanf("%lf%lf%lf", &w0, &w, &m);
	double l = 0, r = 10, mid;
	while (r - l > 1e-6) {
		mid = (l + r) / 2;
		if (isblue(mid / 100) == true) l = mid;
		else r = mid;
	}
	printf("%lf\n", mid * 100);
	printf("%lf\n", l * 100);
	printf("%lf\n", r * 100);
	return 0;
}