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
    int sum = 0;
    for(int i = 0; i < rows; i++){
        int maxVal = a[0][i];
        for(int j = 1; j < cols; j++){
            if(a[i][j] > maxVal){
                maxVal = a[i][j];
            }
        }
        sum += maxVal;
    }
    cout << sum;
    return 0;
}
