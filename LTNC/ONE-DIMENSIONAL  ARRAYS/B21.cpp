#include<bits/stdc++.h>
using namespace std;

int findLastEven(int a[], int n){
    for(int i = n - 1; i >= 0; i--){
        if(a[i] % 2 == 0){
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
    int res = findLastEven(a, n);
    if(res != -1){
        cout << "So chan cuoi cung trong mang la: " << res;
    } else{
        cout << "-1";
    }
    
    return 0;
}