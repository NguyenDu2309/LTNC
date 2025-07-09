#include<bits/stdc++.h>
using namespace std;

int findSmallest(int a[], int n){
    int min = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[min]){
            min =  i;
        }
    }   
    return min;
}

int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = findSmallest(a, n);
    cout << "Vi tri cua so nho nhat la: " << res;
    
    return 0;
}