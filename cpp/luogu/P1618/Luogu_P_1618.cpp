// https://www.luogu.com.cn/problem/P1618
#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int fsnum;
int senum;
int sdnum;
int arr[4];
int st[10];
bool flag = false;
bool flag0 = false;

bool check(int senum, int sdnum) {
    if (senum <= 99 || sdnum <= 99 || senum >= 1000 || sdnum >= 1000) {
        return false;
    }
    // cout << "sdnum = " << sdnum << endl;
    int sege = senum % 10;
    int seshi = senum / 10 % 10;
    int sebai = senum / 100;
    int sdge = sdnum % 10;
    // cout << "sdge = " << sdge << endl;
    int sdshi = sdnum / 10 % 10;
    // cout << "sdshi = " << sdshi << endl;
    int sdbai = sdnum / 100;
    // cout << "sdbai = " << sdbai << endl;
    // cout << sebai << seshi << sege << endl;
    // cout << sdbai << sdshi << sdge << endl;
    st[sege]++;
    st[seshi]++;
    st[sebai]++;
    st[sdge]++;
    st[sdshi]++;
    st[sdbai]++;
    for (int i = 1; i <= 9; i++) {
        if (st[i] == 0) {
            st[sege]--; // 回溯
            st[seshi]--;
            st[sebai]--;
            st[sdge]--;
            st[sdshi]--;
            st[sdbai]--;
            return false;
        }
    }
    st[sege]--; // 回溯
    st[seshi]--;
    st[sebai]--;
    st[sdge]--;
    st[sdshi]--;
    st[sdbai]--;
    return true;
}
void dfs(int x) { // x 表示当前的位数
    if (x > 3) {

        // for (int i = 1; i < 4; i++) {
        //     cout << arr[i];
        // }
        // cout << endl;
        fsnum = arr[1] * 100 + arr[2] * 10 + arr[3];
        if (fsnum % a != 0) {
            return;
        }
        senum = fsnum / a * b;
        sdnum = fsnum / a * c;
        // cout << "fsnum = " << fsnum << endl;
        // cout << "senum = " << senum << endl;
        // cout << "sdnum = " << sdnum << endl;
        if (check(senum, sdnum) == true) {
            cout << fsnum << " " << senum << " " << sdnum << endl;
            flag0 = true;
        }
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (st[i] != 0)
            continue;

        st[i]++;
        arr[x] = i;
        dfs(x + 1);
        arr[x] = 0; // 回溯
        st[i]--;
    }
    return;
}

int main() {
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "No!!!";
        return 0;
    }
    dfs(1);
    if (flag0 == false) {
        cout << "No!!!";
    }
    return 0;
}