// https://www.luogu.com.cn/problem/P1101
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
char g[N][N];
int stans[N][N]; // 最终标记数组
string word = "yizhong";
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y, int dir, int step, vector<pair<int, int>> &path) {
    if (step == word.size()) {
        for (auto &p : path)
            stans[p.first][p.second] = 1;
        return;
    }

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 1 || nx > n || ny < 1 || ny > n)
        return;
    if (g[nx][ny] != word[step])
        return;

    path.push_back({nx, ny});
    dfs(nx, ny, dir, step + 1, path);
    path.pop_back(); // 回溯
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> g[i][j];

    // 遍历每个起点和所有方向
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == word[0]) {
                for (int dir = 0; dir < 8; ++dir) {
                    vector<pair<int, int>> path;
                    path.push_back({i, j});
                    dfs(i, j, dir, 1, path);
                }
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << (stans[i][j] ? g[i][j] : '*');
        }
        cout << endl;
    }
    return 0;
}
