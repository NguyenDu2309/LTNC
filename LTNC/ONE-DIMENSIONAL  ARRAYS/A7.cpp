#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0 && a[i] < 20){
            cout << "a[" << i << "]" << ": " << a[i] << endl;
        }
    }
    return 0;
}