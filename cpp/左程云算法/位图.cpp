// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 10;
int T = 1;
int n;

class myBitset {
    vector<int> a;

  public:
    myBitset(int n) { vector<int> a((n + 31) / 32, 0); }
    void add(int num) { a[num / 32] |= (1 << (num % 32)); }
};

void solve() {
    int n, num;
    cin >> n >> num;

    // 创建
    vector<int> set((n + 31) / 32, 0);
    bitset<N> a;

    // 设置num位为1
    a.set(num);
    set[num / 32] |= (1 << (num % 32));

    // 清除num位(设置为0)
    // a.reset(num);
    // set[num / 32] &= ~(1 << (num % 32));

    debug(a[0]);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    a.flip();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    debug(a.count());
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