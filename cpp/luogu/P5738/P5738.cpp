#include <iomanip>
#include <iostream>
using namespace std;
const int N = 110;

void min_max(int *a, int n) {
    int maxflag = 0, minflag = 0;
    int max = -1, min = 11;
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if (min > a[i]) {
            min = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == max && maxflag == 0) {
            a[i] = 0;
            maxflag = 1;
        }
        if (a[i] == min && minflag == 0) {
            a[i] = 0;
            minflag = 1;
        }
    }
}

int main() {
    int n, m;
    int scores[N][N];
    double sum[N] = {0};
    double avescore[N] = {0};
    double max_avescore = -1;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> scores[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        min_max(scores[i], m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i] += scores[i][j];
            avescore[i] = sum[i] / (m - 2);
        }
    }
    for (int i = 0; i < n; i++) {
        if (max_avescore < avescore[i]) {
            max_avescore = avescore[i];
        }
    }

    cout << fixed << setprecision(2) << max_avescore << endl;
    return 0;
}