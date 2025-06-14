#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl

const int N = 1e5 + 10;
int n;
map<string, int> mp;
string name;
int op;
int score;

void solve() {
    cin >> n;
    while (n--) {
        cin >> op;
        switch (op) {
        case 1: {
            cin >> name >> score;

            mp[name] = score;
            cout << "OK" << endl;

            break;
        }
        case 2: {
            cin >> name;
            if (mp.count(name) == 1) {
                cout << mp[name] << endl;
            } else {
                cout << "Not found" << endl;
            }
            break;
        }
        case 3: {
            cin >> name;
            if (mp.count(name) == 1) {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Not found" << endl;
            }
            break;
        }
        case 4: {
            cout << mp.size() << endl;
            break;
        }
        }
    }

    return;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}