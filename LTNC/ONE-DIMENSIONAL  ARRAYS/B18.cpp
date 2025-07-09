#include<bits/stdc++.h>
using namespace std;

int findPositive(int a[], int n){
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            return i;
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
    int res = findPositive(a, n);
    if(res != -1){
        cout << "Vi tri cua so nguyen duong dau tien la: " << res;
    } else{
        cout << "-1";
    }
    return 0;
}