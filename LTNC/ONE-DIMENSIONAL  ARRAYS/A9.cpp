#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2){
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
    int n, a[100];
    cout << "Nhap n: ";
    cin >> n;
    bool found = false;
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    // }
    cout << "So nho nguyen to hon n la: ";
    for(int i = 2; i < n; i++){
        if(isPrime(i)){
            cout << i << " ";
            found = true;
        }
    }

    if(!found){
        cout << "Khong co so nguyen to nho hon " << n;
    }
    return 0;
}