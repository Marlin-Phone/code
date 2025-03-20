// https://www.luogu.com.cn/problem/P1598
#include <bits/stdc++.h>
using namespace std;

string str[5];
vector<vector<char>> zimu(27, vector<char>(0));
int num[27];
int num_max = -1;
char zi[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
               'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
               'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
// zimu[27][410];

int main() {
    for (int i = 1; i <= 4; i++) {
        getline(cin, str[i]);
        for (int j = 0; j < str[i].length(); j++) {
            if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
                zimu[str[i][j] - 'A' + 1].push_back('*');
                num[str[i][j] - 'A' + 1]++;
            }
        }
    }
    for (int i = 1; i <= 26; i++) { // 获得num的最大值
        num_max = max(num_max, num[i]);
    }

    for (int i = 0; i < num_max; i++) { // 行遍历
        for (int j = 1; j <= 26; j++) { // 列遍历
            if (num[j] < num_max - i) { // 该字母个数少于mun_max - i则
                cout << "  ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= 26; i++) {
        cout << zi[i] << " ";
    }
    return 0;
}