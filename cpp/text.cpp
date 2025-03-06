#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3 + 10;
int vec[N][N];
int n;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> vec[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vec[i][j] = vec[i - 1][j] + vec[i][j - 1]
        }
    }

    return 0;
}