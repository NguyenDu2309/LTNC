#include<bits/stdc++.h>
using namespace std;

void findOneToX(int a[], int n, int x){
    bool found = false;
    for(int i = 0; i < n; i++){
        if(a[i] > 0 && a[i] <= x){
            cout << a[i] << " ";
            found = true;
        }
    }
    if(!found){
         cout << "Khong co phan tu nao nam trong khoang tu 1 den " << x;
    }
    cout << endl;
}

int main(){
    int a[100], n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << endl;
    cout << "Nhap so x: ";
    cin >> x;
    cout << "Cac phan tu trong mang co gia tri tu 1 den " << x << " la: ";
    findOneToX(a, n, x);

}