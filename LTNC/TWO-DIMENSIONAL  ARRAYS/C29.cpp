#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

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
    int lastRow = 0, lastCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(isPrime(a[i][j])){
                lastRow = i;
                lastCol = j;
            }
        }
    }
    cout << "So nguyen to cuoi cung trong ma tran o vi tri: " << lastRow  << " "<< lastCol;
    return 0;
}
