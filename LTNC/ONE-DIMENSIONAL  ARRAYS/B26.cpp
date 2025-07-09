#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[100], n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int countP = 0;
    int countN = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            countN++;
        }
        else if(a[i] > 0){
            countP++;
        }
    }
    cout << "So luong so nguyen duong trong mang la: " << countP << endl;
    cout << "So luong so nguyen am trong mang la: " << countN << endl;
    return 0;
}