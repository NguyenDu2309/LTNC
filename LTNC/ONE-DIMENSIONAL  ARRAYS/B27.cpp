#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[100], n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int countOdd = 0;
    int countEven = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            countOdd++;
        }
        else if(a[i] % 2 == 0){
            countEven++;
        }
    }
    cout << "So luong so le trong mang la: " << countOdd << endl;
    cout << "So luong so chan trong mang la: " << countEven << endl;
    return 0;
}