// https://www.luogu.comm.cn/problem/P5730
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n; // 数字的位数
string nums;
char prtnum[10][N];
int i_index = 1;
int j_index = 1;

void printnum(char num) {
    int j0 = j_index;
    switch (num) {
    case '0': {
        while (j_index != j0 + 2 && i_index != 5) {
            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '1': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '2': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '3': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '4': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '5': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '6': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '7': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '8': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    case '9': {
        while (j_index != j0 + 2 && i_index != 5) {

            prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = '.';
            j_index++, prtnum[i_index][j_index] = 'X';

            j_index = j0, i_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
            j_index++, prtnum[i_index][j_index] = 'X';
        }
        break;
    }
    }
}
int main() {
    cin >> n;
    cin >> nums;
    for (int i = 0; i < n; i++) {
        printnum(nums[i]);
        j_index++;
        for (i_index = 1; i_index <= 5; i_index++) {
            prtnum[i_index][j_index] = '.';
        }
        i_index = 1;
        j_index++;
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 4 * n - 1; j++) {
            cout << prtnum[i][j];
        }
        cout << endl;
    }

    return 0;
}