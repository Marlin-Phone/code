//一维前缀和 O(n)
/*
输入：
10 2					
1 2 3 4 5 6 7 8 9 10	
2 4						
4 8

n, k
a[n] = {1, 2, 3, 4, 5, 6, ...}
l, r
l, r
*/

#define _CRT_SECURE_NO_WARNINGS //_crt_secure_no_warnings
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int main() {
	int n, k, l, r, a[N], S[N];
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		S[i] = S[i - 1] + a[i];
	}

	while (k--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", S[r] - S[l - 1]);
	}

	return 0;
}