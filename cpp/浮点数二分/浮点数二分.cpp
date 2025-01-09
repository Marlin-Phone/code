//原视频讲解 https://www.bilibili.com/video/BV1HD4y1K7iD/
/*
输入样例：
1000.00
输出样例：
10.000000
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

double i, n;
bool check(double i, double n) { //blue
	if (i * i * i >= n) return true;
	else return false;
}
int main() {
	scanf("%lf", &n);
	
	double l = -100, r = 100;
	while (r - l > 1e-7) {
		double mid = (l + r) / 2;
		if (check(mid, n)) r = mid;
		else l = mid;
	}

	printf("%lf\n", l);
	printf("%lf\n", r);

	return 0;
}