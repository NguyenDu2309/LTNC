
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Hay nhap mang a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || i + j ==  n-1){
                sum += a[i][j];
            }
        }
    }
    cout << sum;
    return 0;
}
