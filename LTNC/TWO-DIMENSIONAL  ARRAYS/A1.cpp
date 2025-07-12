#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, col;
    cout << "Nhap so hang: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> col;
    int a[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
            if (a[i][j] < 0) {
                cout << "Mang khong hop le!" << endl;
                return 0;
            }
        }
    }
    cout << "Mang a la: " << endl;
     for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(a[i][j] > 0){
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}