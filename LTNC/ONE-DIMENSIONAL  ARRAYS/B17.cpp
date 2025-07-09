#include<bits/stdc++.h>
using namespace std;

int findNegative(int a[], int n){
    int maxNegative = INT_MIN;
    bool found = false;
    for(int i = 0; i < n; i++){
        if(a[i] < 0 && (!found || a[i] > maxNegative)){
            maxNegative = a[i];
            found = true;
        }
    }
    return found ? maxNegative : 0;
}

int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = findNegative(a, n);
    
    if(res != 0){
        cout << "So am lon nhat trong mang la: " << res;
    } else{
        cout << "Khong co so am trong mang!";
    }
    return 0;
}