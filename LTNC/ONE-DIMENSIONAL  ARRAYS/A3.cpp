#include<bits/stdc++.h>
using namespace std;

int main(){
    double n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    srand(time(0));
    for(int i = 0; i < n; i++){
        a[i] = -rand() % 100 + 1;
    }
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]" << ": " << a[i] << endl;
    }
    return 0;
}