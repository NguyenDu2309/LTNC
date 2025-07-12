
#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1) return false;
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}


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
    int sum = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(isPerfect(a[i][j])){
                sum += a[i][j];
            }
        }
    }
    cout << sum;
    return 0;
}
