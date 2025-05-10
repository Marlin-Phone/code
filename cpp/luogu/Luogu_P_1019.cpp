#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 25;
int n;
string words[N]; // 存单词
int used[N];     // 记录每个单词的使用次数
char start;
int g[N][N]; // g[i][j] 存第i个值能否接到第j个单词后面
int res = 0;

void dfs(string dragon, int x) {
    res = max(res, (int)dragon.size());

    used[x]++;
    for (int i = 0; i < n; i++) {
        if (g[x][i] && used[i] < 2) {
            dfs(dragon + words[i].substr(g[x][i]), i);
        }
    }
    used[x]--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cin >> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string a = words[i], b = words[j];
            for (int k = 1; k < min(a.size(), b.size()); k++) {
                if (a.substr(a.size() - k) == b.substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (words[i][0] == start) {
            dfs(words[i], i);
        }
    }

    cout << res << endl;

    return 0;
}