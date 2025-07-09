#include<bits/stdc++.h>
using namespace std;

int findMax(int a[], int n){
    int max = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[max]){
            max = i;
        }
    }
    return max;
}

int main(){
    int n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxX = findMax(a, n);
    cout << "Gia tri max cua mang la: " << maxX;
    return 0;
}