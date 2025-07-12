#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }

    for (int k = 0; k <= 2 * (n - 1); k++) {
        int minVal = INT_MAX;
        bool x = false;

        for (int i = 0; i < n; i++) {
            int j = k - i;
            if (j >= 0 && j < n) {
                if (a[i][j] < minVal) {
                    minVal = a[i][j];
                    x = true;
                }
            }
        }

        if (x)
            cout << "tong i+j=" << k << ": " << minVal << endl;
    }

    return 0;
}
