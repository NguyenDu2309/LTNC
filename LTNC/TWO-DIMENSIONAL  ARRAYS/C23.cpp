#include<bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols;
    cout << "Nhap so hang: ";
    cin >> rows;
    cout << "Nhap so cot: ";
    cin >> cols;
    int a[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    int min = INT_MAX, minRow = 0, minCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    cout << "So nho nhat trong ma tran o vi tri: " << minRow  << " "<< minCol;
    return 0;
}
