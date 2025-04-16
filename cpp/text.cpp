#include <bits/stdc++.h>
using namespace std;

string A, B;
bool Aiswrong, Biswrong;
int numA, numB;

bool check(char ch, int i) {
    if (i == 0) {
        if (ch >= '1' && ch <= '9') {
            return true;
        } else {
            return false;
        }
    } else {
        if (ch >= '0' && ch <= '9') {
            return true;
        } else {
            return false;
        }
    }
}
int main() {
    cin >> A >> B;
    for (int i = 0; i < A.size(); i++) {
        if (check(A[i], i)) {
            continue;
        } else {
            Aiswrong = true;
        }
    }

    for (int i = 0; i < B.size(); i++) {
        if (check(B[i], i)) {
            continue;
        } else {
            Biswrong = true;
        }
    }
    if (!Aiswrong) {
        for (int i = 0; i < A.size(); i++) {
            numA *= 10;
            numA += A[i] - '0';
        }
        if (numA > 1000) {
            Aiswrong = true;
        }
    }
    if (!Biswrong) {
        for (int i = 0; i < B.size(); i++) {
            numB *= 10;
            numB += B[i] - '0';
        }
        if (numB > 1000) {
            Biswrong = true;
        }
    }

    if (Aiswrong == false) {
        cout << A << " + ";
    } else {
        cout << "? + ";
    }

    if (Biswrong == false) {
        cout << B << " ";
    } else {
        cout << "? ";
    }

    cout << "= ";

    if (Aiswrong || Biswrong) {
        cout << "?";
    } else {

        cout << numA + numB;
    }

    return 0;
}