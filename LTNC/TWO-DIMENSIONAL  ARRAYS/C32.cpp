#include <iostream>
using namespace std;

int main() {
    int a[100][100], b[100][100];
    bool visited[100][100] = {false};
    int m, n;

    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "b[" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }

    cout << "\nCac phan tu chung: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = a[i][j];

            bool found = false;
            for (int x = 0; x < m && !found; x++) {
                for (int y = 0; y < n; y++) {
                    if (b[x][y] == val && !visited[x][y]) {
                        cout << val << " ";
                        visited[x][y] = true;
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    cout << endl;
    return 0;
}
