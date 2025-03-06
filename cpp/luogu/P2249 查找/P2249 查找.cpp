// https://www.luogu.com.cn/problem/P2249
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


bool isblue(int num, int temp) {
	if(num < temp) return true;
	else return false;
}
int main(){
	int n, m, temp;	
	scanf("%d%d", &n, &m);
	vector<int> num(n + 10);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		int l = 0, r = n + 1;
		while (l + 1 != r) {
			int mid = (l + r) / 2;
			if (isblue(num[mid], temp) == true) l = mid;
			else r = mid;
		}
		if(num[r] == temp) printf("%d ", r);
		else printf("-1 ");
	}

	return 0;
}