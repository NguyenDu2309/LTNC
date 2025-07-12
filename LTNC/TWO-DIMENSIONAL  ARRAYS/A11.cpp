#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows;
    cout << "Nhap so cot: ";
    cin >> rows;
    int a[rows][rows] = {0};

    for (int i = 0; i < rows; i++) {
        a[i][0] = 1;           
        a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

    cout << "Tam giac Pascal:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int space = 0; space < rows - i - 1; space++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
