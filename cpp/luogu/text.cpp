#include <bits/stdc++.h>
using namespace std;

void dfs(int x) { dfs(x + 1); }
int main() {
    dfs(1);

    return 0;
}