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
    int n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(isPrime(a[i])){
            cout << "a[" << i << "]" << ": " << a[i] << endl;
        }
    }
    return 0;
}