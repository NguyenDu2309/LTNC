#include<bits/stdc++.h>
using namespace std;

int findLast(int a[], int n, int x){
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, a[100], x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    bool found = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    int p = findLast(a, n, x);
    if(p != -1){
        cout << "Vi tri cua phan tu " << x << " xuat hien lan cuoi o: " << p  << endl;
    } else{
        cout << "Khong tim thay phan tu " << x << " trong mang" << endl;
    }
    return 0;
}