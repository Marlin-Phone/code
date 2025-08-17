#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(x) for (ll i = 1; i <= x; ++i)
#define f1(x) for (ll j = 1; j <= x; ++j)
#define lowbit(x) ((-x) & x)
#define PII pair<ll, ll>
#define yes cout << "YES\n";

#define eps 1e-7
#define il inline

struct no {
    ll a, b, id;
};

constexpr ll mod = 1e9 + 7;

il void solve() {
    ll n;
    cin >> n;
    map<ll, vector<ll>> mp1;
    vector<no> a(n + 1);
    f(n) {
        cin >> a[i].a >> a[i].b;
        a[i].id = i;
        mp1[a[i].a].push_back(i);
    }
    ll maxx = 0;
    sort(a.begin(), a.end(), [](no a, no b) {
        if (a.a == b.a) {
            return a.b < b.b;
        }
        return a.a < b.a;
    });
    // 比某个等级高的中最大的团体个数
    ll ji = 0, pre = 10000000000;
    vector<ll> ans;
    ll pos = n;

    ll cnt = 1;
    for (ll i = n; i >= 1; i--) {
        if (pre != a[i].a) {
            pre = a[i].a;
            ji = maxx;
            cnt = 1;
        }

        if (maxx < min(ji, a[i].b) + cnt) {
            maxx = min(ji, a[i].b) + cnt;
            pos = i;
        }
        cnt++;
    }
    cout << maxx << "\n";
    vector<ll> now;
    vector<ll> ans1;
    // 需要维护一个大于当前pos等级的最大团体数量
    maxx = 0;
    pre = 1000000000000;
    for (ll i = n; i >= pos; i--) {
        if (pre != a[i].a) {
            pre = a[i].a;
            ji = maxx;
            cnt = 1;
            now.clear();
            ans1 = ans;
        }
        now.push_back(a[i].id);
        if (maxx < min(ji, a[i].b) + cnt) {
            maxx = min(ji, a[i].b) + cnt;
            // 考虑取min后要是为a[i].b则给ans的大小变为a[i].b
            ans.clear();
            for (ll j = 1; j <= min(ji, a[i].b); ++j) {
                ans.push_back(ans1[j - 1]);
            }
            for (auto j : now) {
                ans.push_back(j);
            }
        }
        cnt++;
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}