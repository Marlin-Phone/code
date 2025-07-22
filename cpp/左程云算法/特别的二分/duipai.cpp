
#include <bits/stdc++.h>
using namespace std;

int main() {
    system("g++ -std=c++11 baoli.cpp -o baoli.exe");
    system("g++ -std=c++11 zhengjie.cpp -o zhengjie.exe");
    system("g++ -std=c++11 makedata.cpp -o makedata.exe");

    while (1) {
        system("makedata.exe > makedata.txt");
        system("baoli.exe < makedata.txt > baoli.txt");
        system("zhengjie.exe < makedata.txt > zhengjie.txt");

        if (system("fc baoli.txt zhengjie.txt")) {
            cout << "Wrong Answer" << endl;
            system("type makedata.txt");
            system("type baoli.txt");
            system("type zhengjie.txt");
            break;
        } else {
            cout << "Accepted" << endl;
        }
    }

    return 0;
}