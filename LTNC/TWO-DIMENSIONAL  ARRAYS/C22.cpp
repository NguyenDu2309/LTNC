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
    int max = 0, maxRow = 0, maxCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(a[i][j] > max){
                max = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    cout << "So lon nhat trong ma tran o vi tri: " << maxRow  << " "<< maxCol;
    return 0;
}
