#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Vi tri cua cac so nguyen to trong mang la: ";
    for(int i = 0; i < n; i++){
        if(isPrime(a[i])){
            cout << i << " ";
        }
    }
    return 0;
}