#include<bits/stdc++.h>
using namespace std;

int findMin(int a[], int n){
    int min = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[min]){
            min = i;
        }
    }
    return min;
}

int main(){
    int n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int minX = findMin(a, n);
    cout << "Gia tri min cua mang la: " << minX;
    return 0;
}