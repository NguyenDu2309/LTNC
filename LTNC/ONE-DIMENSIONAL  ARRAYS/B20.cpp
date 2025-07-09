#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Boi so cua 3 va 5 trong mang la: ";
    for(int i = 0; i < n; i++){
        if(a[i] % 3 == 0 && a[i] % 5 == 0){
            cout << a[i] << " ";
        }
    }   
    
    return 0;
}