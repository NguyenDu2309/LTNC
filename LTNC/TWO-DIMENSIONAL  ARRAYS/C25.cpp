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
    int max = INT_MIN;
    int lastRow = 0, lastCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(a[i][j] % 2  != 0 && a[i][j] < 0 && a[i][j] > max){
                max = a[i][j];
                lastRow = i;
                lastCol = j;
            }
        }
    }
    cout << "So le, am lon nhat trong ma tran la so" << max <<  "o vi tri: " << lastRow  << " "<< lastCol;
    return 0;
}
