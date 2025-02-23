#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int L[N];
int R[N];
long long count = 0;

int main() {
    int N, M; // N 个谜语 M个灯笼(1-M)

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
    }

    int p = 1;
    for (int i = 1; i <= N; i++) {
        while (!(L[i] <= p && p <= R[i])) {
            if (p < L[i]) {
                count += L[i] - p;
                p = L[i];
            }
            if (R[i] < p) {
                count += p - R[i];
                p = R[i];
            }
        }
    }

    cout << count;

    return 0;
}