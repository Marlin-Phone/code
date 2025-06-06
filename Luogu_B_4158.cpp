// https://luogu.com.cn/problem/B4158
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e7;
int T = 1;
int n;
vector<string> vec_prime;
vector<bool> isPrime(N, true);

// bool isPrime(int num){
//     if (num < 2){
//         return false;
//     }
//     for (int i = 2; i * i <= num; i++){
//         if(num % i == 0){
//             return false;
//         }
//     }
//     return true;
// }
void getprime() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
}
void solve() {
    cin >> n;
    getprime();
    for (int i = 1; i <= 1000; i++) {
        if (isPrime[i]) {
            cout << i << endl;
        }
    }

    // while(n--){
    //     string str;
    //     cin >> str;
    //     for (int i = 0; i < vec_prime.size(); i++){
    //         if(vec_prime[i].size() == str.size()){
    //             for (int i = 0; i < str.size(); i++){
    //                 if()
    //             }
    //         }
    //     }
    // }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}