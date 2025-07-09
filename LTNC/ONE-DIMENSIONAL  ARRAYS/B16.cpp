#include<bits/stdc++.h>
using namespace std;

int firstNegative(int a[], int n){
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            return a[i];
        }
    }
    return -1;
}

int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = firstNegative(a, n);
    
    if(res != 0){
        cout << "So am dau tien trong mang la: " << res;
    } else{
        cout << "Khong co so am trong mang!";
    }
    return 0;
}