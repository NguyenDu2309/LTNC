#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    cout << "Phan tu nam duoi duong cheo chinh la: " << endl;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j){
                cout << a[i][j] << " ";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}