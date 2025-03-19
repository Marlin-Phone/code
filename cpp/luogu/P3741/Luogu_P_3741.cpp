// https://www.luogu.com.cn/problem/P3741
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
string s;
int ans = 0;
int flag = 0;
bool st[N];

int main() {
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'V' && s[i + 1] == 'K') {
            st[i] = true;
            st[i + 1] = true;
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V' && s[i + 1] == 'V' && st[i] != true &&
            st[i + 1] != true) {
            ans++;
            break;
        } else if (s[i] == 'K' && s[i + 1] == 'K' && st[i] != true &&
                   st[i + 1] != true) {
            ans++;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}