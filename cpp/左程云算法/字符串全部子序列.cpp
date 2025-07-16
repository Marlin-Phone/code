#include <bits/stdc++.h>
using namespace std;

const int N = 100;
string str;
bool st[N];
set<string> set_str;

void dfs(int x) {
    if (x >= str.size()) {
        string temp;
        for (int i = 1; i <= str.size(); i++) {
            if (st[i]) {
                temp.push_back(str[i]);
            }
        }
        set_str.insert(temp);
        return;
    }

    // 选
    st[x] = 1;
    dfs(x + 1);

    // 不选
    st[x] = 0;
    dfs(x + 1);
}
int main() {
    vector<string> ans;

    str.push_back(' ');
    string temp;
    cin >> temp;

    str += temp;

    dfs(1);

    // cout << set_str.size() << endl;
    for (auto it : set_str) {
        ans.push_back(it);
    }

    // return ans;

    return 0;
}