/*
输入：
4 5 2
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 1 3 3
1 1 4 5

n m k
[A]
(x1, y1)(x2, y2)
(x1, y1)(x2, y2)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int a[N][N];
int S[N][N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			S[i][j] = a[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
		}
	}

	while (k--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
		printf("%d\n", ans);
	}
	
	return 0;
}