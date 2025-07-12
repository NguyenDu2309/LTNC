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
    int maxSum = INT_MIN;
    for (int d = -(cols - 1); d <= rows - 1; d++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            int j = i - d;
            if (j >= 0 && j < cols) {
                sum += a[i][j];
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    cout << maxSum << endl;
    return 0;
}