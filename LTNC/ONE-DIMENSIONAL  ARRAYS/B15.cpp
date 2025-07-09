#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) {
        return false;
    }
    for(int i = 2; i < n; i++){
        int sqrtN = sqrt(n);
        if(sqrtN * sqrtN == n){
            return true;
        }
    }
    return false;
}

int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Vi tri cua cac so nguyen to (lon hon 23) trong mang la: ";
    for(int i = 0; i < n; i++){
        if(isPrime(a[i]) && (a[i] > 23)){
            cout << i << " ";
        }
    }
    return 0;
}