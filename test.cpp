#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

const int N = 1e3 + 10;
vector<vector<int>> g(N + 10, vector<int>(N + 10, 0));


double average_time1 = 0;
double average_time2 = 0;

void solve() {

    // 测试速度
    auto start = chrono::high_resolution_clock::now();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            g[i][j] = 1;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    // cout << "Time taken: " << duration.count() << " ms" << endl;
    average_time1 += duration.count();

    // 再次测试速度
    start = chrono::high_resolution_clock::now();
    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= N; i++){
            g[i][j] = 2;
        }
    }
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    // cout << "Time taken: " << duration.count() << " ms" << endl;
    average_time2 += duration.count();

}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t0 = 10000;
    int t = t0;
    // cin >> t;
    // 计算平均时间
    while (t--) {
        solve();
    }

    average_time1 /= t0;
    average_time2 /= t0;
    cout << "Average time 1: " << average_time1 << " ms" << endl;
    cout << "Average time 2: " << average_time2 << " ms" << endl;

    return 0;
}