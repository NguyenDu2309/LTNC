#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    int max = a[0][0];
    for (int i = 1; i < n; i++) {
        if(a[i][i] > max){
            max = a[i][i];
        }
    }
    cout << "So lon nhat tren duong cheo chinh cua ma tran vuong la: " << max;
    return 0;
}
