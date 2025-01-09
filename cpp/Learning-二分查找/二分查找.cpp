//原理题目讲解：https://www.bilibili.com/video/BV1fA411z7ru/
//五点七边：https://www.bilibili.com/video/BV1d54y1q7k7/
/*
输入用例：
6 3
1 2 2 3 3 4
3 
4
5
输出用例：
3 4
5 5
-1 -1
***************************************************Accepted*********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

long long count = 0;

const int N = 1e5 + 10;
int n, q;
vector<int> arr(N);
//第一个二分查找找的是：被查找元素的左边界
bool isBlue1(int mid, int x) {
	if (mid < x) return true;
	else return false;
}
int binary_search1(vector<int> arr, int n, int x) {
	int l = -1, r = n;
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		if (isBlue1(arr[mid], x)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (arr[r] == x) return r;//返回红色区域边界
	else return -1;//找不到就返回-1
}

//第二个二分查找找的是：被查找元素的右边界
bool isBlue2(int mid, int x) {
	if (mid <= x) return true;
	else return false;
}
int binary_search2(vector<int> arr, int n, int x) {
	int l = -1, r = n;
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		if (isBlue2(arr[mid], x)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (arr[l] == x) return l;//返回蓝色区域边界
	else return -1;//找不到就返回-1
}

//主函数
int main() {
	scanf("%d%d", &n, &q);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	while (q--) {
		int x;
		scanf("%d", &x);
		int res1 = binary_search1(arr, n, x);
		if (res1 == -1) {					//优化
			printf("-1 -1");
			continue;
		}
		int res2 = binary_search2(arr, n, x);
		printf("%d %d\n", res1, res2);
	}

	return 0;
}