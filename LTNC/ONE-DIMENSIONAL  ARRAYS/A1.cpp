#include<bits/stdc++.h>
using namespace std;

int main(){
    double n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}