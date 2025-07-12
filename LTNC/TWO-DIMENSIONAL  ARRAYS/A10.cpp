#include<bits/stdc++.h>
using namespace std;

int main(){
    const int rows = 9;
    const int cols = 14;
    int a[rows][cols];
    srand(time(0));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            a[i][j] = rand() % 100;
            // cin >> a[i][j];
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}