#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll hpa, hpb;
        cin >> n >> hpa >> hpb;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> A_atk, B_atk;
        int da = 0, db = 0;
        for (int x : a) {
            if (x == -1)
                da++;
            else
                A_atk.push_back(x);
        }
        for (int x : b) {
            if (x == -1)
                db++;
            else
                B_atk.push_back(x);
        }
        int aa = A_atk.size();
        int ba = B_atk.size();

        sort(A_atk.rbegin(), A_atk.rend());
        vector<ll> F(aa + 1, 0);
        for (int i = 1; i <= aa; i++)
            F[i] = F[i - 1] + A_atk[i - 1];

        sort(B_atk.begin(), B_atk.end());
        vector<ll> G(ba + 1, 0);
        for (int i = 1; i <= ba; i++)
            G[i] = G[i - 1] + B_atk[i - 1];

        int L = max(0, n - da - db);
        int R = min(aa, ba);
        bool win = false;
        for (int z = L; z <= R; z++) {
            if (F[z] >= hpb && G[z] < hpa) {
                win = true;
                break;
            }
        }
        cout << (win ? "yes" : "no") << '\n';
    }
    return 0;
}