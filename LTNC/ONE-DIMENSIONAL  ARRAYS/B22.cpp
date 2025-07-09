#include<bits/stdc++.h>
using namespace std;

int findLargestOdd(int a[], int n){
    int max = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] % 2 != 0 && a[i] > a[max]){
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
    int res = findLargestOdd(a, n);
    if(res != -1){
        cout << "So le lon nhat trong mang la: " << res;
    } else{
        cout << "-1";
    }
    
    return 0;
}