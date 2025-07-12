#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    cout << "Cac so nguyen to tren duong cheo phu la:";
    for (int i = 0; i < n; i++) {
        int val = a[i][n - 1 -i];
        if(isPrime(val)){
            cout << val << " ";
        }
    }
    return 0;
}

