#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const float e = 1e-6;

bool existArray(float arr[], int n, float x) {
    for (int i = 0; i < n; i++) {
        if (fabs(arr[i] - x) < e) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    float a[MAX], b[MAX];

    cout << "Nhap so phan tu cua mang a: ";
    cin >> n;
    cout << "Nhap " << n << " phan tu cua mang a:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Nhap so phan tu cua mang b: ";
    cin >> m;
    cout << "Nhap " << m << " phan tu cua mang b:\n";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    //a
    cout << "\nCac phan tu chi xuat hien trong mang a:\n";
    bool foundA = false;
    for (int i = 0; i < n; i++) {
        if (!existArray(b, m, a[i])) {
            cout << a[i] << " ";
            foundA = true;
        }
    }
    if (!foundA) cout << "Khong co.";

    //b
    cout << "\n\nCac phan tu xuat hien trong ca hai mang:\n";
    bool foundCommon = false;
    for (int i = 0; i < n; i++) {
        if (existArray(b, m, a[i])) {
            cout << a[i] << " ";
            foundCommon = true;
        }
    }
    if (!foundCommon) cout << "Khong co.";

    cout << endl;
    return 0;
}
