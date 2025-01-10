#include <cmath>
#include <iostream>
using namespace std;

bool isprime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void getprime(int N, int *primenum, int &n) {
    for (int i = 0; i < N; i++) {
        if (isprime(i)) {
            primenum[n] = i;
            n++;
        }
    }
}

void print(int N, int *primenum, int n) {
    for (int i = 4; i <= N; i += 2) {
        int j, k;
        cout << i << "=";
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= n; k++) {
                if (i == primenum[j] + primenum[k]) {
                    cout << primenum[j] << "+" << primenum[k];
                    break;
                }
            }
            if (k <= n)
                break;
        }
        cout << endl;
    }
}

void function(int N) {}

int main() {
    int N, n = 0; // N为偶数大小, n为素数个数
    cin >> N;
    int primenum[N] = {0};

    getprime(N, primenum, n);
    print(N, primenum, n);

    return 0;
}