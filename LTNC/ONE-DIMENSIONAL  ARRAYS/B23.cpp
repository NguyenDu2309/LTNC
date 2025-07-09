#include<bits/stdc++.h>
using namespace std;

void swapLargestSmallest(int a[], int n){
    int max = 0;
    int min = 0;
    if(n <= 1) {
        return;
    }
    for(int i = 1; i < n; i++){
        if(a[i] > a[max]){
            max = i;
        }
        if(a[i] < a[max]){
            min = i;
        }
    }   
    swap(a[max], a[min]);
}

int main(){
    int a[100], n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    swapLargestSmallest(a, n);
    cout << "Mang sau khi hoan doi max, min: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    } 
    
    return 0;
}