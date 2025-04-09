// https://luogu.com.cn/problem/P5266
// map
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int q, op;
string name;
int score;
// struct node {
//     string name;
//     int score;
// };
map<string, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> op;
        switch (op) {
        case 1: {
            cin >> name;
            cin >> score;
            mp[name] = score;
            cout << "OK" << endl;
            break;
        }
        case 2: {
            cin >> name;
            auto it = mp.find(name);
            if (it != mp.end()) {
                cout << mp[name] << endl;
            } else {
                cout << "Not found" << endl;
            }
            break;
        }
        case 3: {
            cin >> name;
            auto it = mp.find(name);
            if (it == mp.end()) {
                cout << "Not found" << endl;
            } else {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            }
            break;
        }
        case 4: {
            cout << mp.size() << endl;
            break;
        }
        }
    }

    return 0;
}