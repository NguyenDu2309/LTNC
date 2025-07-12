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
    int sum = 0;
    int maxSum = INT_MIN;
    for (int k = 0; k <= rows + cols - 2; k++) {
        int minVal = INT_MAX;
        bool found = false;

        for (int i = 0; i < rows; i++) {
            int j = k - i;
            if (j >= 0 && j < cols) {
                if (a[i][j] < minVal)
                    minVal = a[i][j];
                found = true;
            }
        }

        if (found)
            sum += minVal;
    }   
    cout << sum << endl;

    return 0;
}
