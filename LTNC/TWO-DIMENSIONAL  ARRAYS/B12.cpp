#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols;
    cout << "Nhap so hang: ";
    cin >> rows;
    cout << "Nhap so cot: ";
    cin >> cols;
    int a[rows][cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    int sumCol;
    cout << "Nhap cot de tinh: ";
    cin >> sumCol;
    int sum = 0;
    for(int i = 0; i < rows; i++){
        sum += a[i][sumCol];
    }
    cout << sum;
    return 0;
}
