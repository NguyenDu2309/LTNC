#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[100], n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Nhap gia tri X: ";
    cin >> x;
    int countX = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            countX++;
        }
    }
    cout << "So lan X xuat hien trong mang la: " << countX << endl;
    return 0;
}