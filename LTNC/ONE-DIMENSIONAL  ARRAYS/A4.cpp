#include<bits/stdc++.h>
using namespace std;

int main(){
    double n, a[100];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    srand(time(0));
    a[0] = rand() % 101 + 100;
    for(int i = 0; i < n; i++){
        int x = rand() % 10 + 1; 
        a[i] = a[i - 1] + x;
    }
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]" << ": " << a[i] << endl;
    }
    return 0;
}