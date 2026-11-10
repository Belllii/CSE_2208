#include <bits/stdc++.h>
using namespace std;
// Calculate determinant
double determinant(double A[10][10], int n) {
    if(n == 1)
        return A[0][0];
    double det = 0;
    double temp[10][10];
    for(int p = 0; p < n; p++) {
        int r = 0, c = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == p)
                    continue;
                temp[r][c++] = A[i][j];
                if(c == n - 1) {
                    c = 0;
                    r++;
                }
            }
        }
        double sign = (p % 2 == 0) ? 1 : -1;
        det += sign * A[0][p] * determinant(temp, n - 1);
    }
    return det;
}

// Calculate cofactor
double cofactor(double A[10][10], int n, int row, int col) {
    double temp[10][10];
    int r = 0, c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == row || j == col)
                continue;
            temp[r][c++] = A[i][j];
            if(c == n - 1) {
                c = 0;
                r++;
            }
        }
    }
    double sign = ((row + col) % 2 == 0) ? 1 : -1;
    return sign * determinant(temp, n - 1);
}
int main() {
    int n;
    cin >> n;
    double A[10][10], C[10][10], inv[10][10];
    cout << "Enter matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    double det = determinant(A, n);
    if(fabs(det) < 1e-12) {
        cout << "Inverse does not exist.\n";
        return 0;
    }
    // Calculate cofactor matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = cofactor(A, n, i, j);
        }
    }
    // Transpose cofactor matrix and divide by determinant
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            inv[i][j] = C[j][i] / det;
        }
    }

    cout << fixed << setprecision(4);

    cout << "\nInverse Matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << inv[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
