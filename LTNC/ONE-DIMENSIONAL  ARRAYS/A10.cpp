#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int n){
    if(n < 0){
        return false;
    }
    else{
        int sqrtN = sqrt(n);
        return sqrtN * sqrtN == n;
    }
}

int main(){
    int n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    bool found = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "So chinh phuong la: ";
    for(int i = 0; i < n; i+=2){
        if(isPerfectSquare(a[i])){
            cout << a[i] << " ";
        }
    }
    return 0;
}