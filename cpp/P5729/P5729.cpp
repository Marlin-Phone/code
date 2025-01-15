#include <iostream>
using namespace std;

const int W = 30, X = 30, H = 30;
int main() {
    int w, x, h;
    int q;
    int count = 0;
    int block[W][X][H] = {0};

    cin >> w >> x >> h;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1 - 1; i < x2; i++) {
            for (int j = y1 - 1; j < y2; j++) {
                for (int k = z1 - 1; k < z2; k++) {
                    block[i][j][k] = 1;
                }
            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < h; k++) {
                if (block[i][j][k] == 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}