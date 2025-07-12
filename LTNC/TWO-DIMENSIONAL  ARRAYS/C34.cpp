#include <iostream>
using namespace std;

int main() {
    int m, n;
    int a[100][100];

    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool isLocalMax = true;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int ni = i + dx;
                    int nj = j + dy;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (a[ni][nj] >= a[i][j]) {
                            isLocalMax = false;
                            break;
                        }
                    }
                }
                if (!isLocalMax) break;
            }

            if (isLocalMax) {
                cout << "a[" << i << "][" << j << "] = " << a[i][j] << endl;
            }
        }
    }

    return 0;
}
