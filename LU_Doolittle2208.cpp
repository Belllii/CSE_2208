#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double A[10][10], L[10][10] = {}, U[10][10] = {};
    double B[10], Y[10], X[10];
    cout << "Enter matrix A:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter matrix B:\n";
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }
    // Doolittle LU Decomposition
    for(int i = 0; i < n; i++) {
        // Calculate U
        for(int k = i; k < n; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }
        // Calculate L
        L[i][i] = 1;
        for(int k = i + 1; k < n; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++) {
                sum += L[k][j] * U[j][i];
            }
            if(fabs(U[i][i]) < 1e-12) {
                cout << "Cannot solve: zero pivot.\n";
                return 0;
            }
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
    // Forward substitution: LY = B
    for(int i = 0; i < n; i++) {
        double sum = 0;
        for(int j = 0; j < i; j++) {
            sum += L[i][j] * Y[j];
        }
        Y[i] = (B[i] - sum) / L[i][i];
    }
    // Backward substitution: UX = Y
    for(int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for(int j = i + 1; j < n; j++) {
            sum += U[i][j] * X[j];
        }
        if(fabs(U[i][i]) < 1e-12) {
            cout << "Cannot solve: zero pivot.\n";
            return 0;
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }
    cout << fixed << setprecision(4);
    cout << "\nL Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << L[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nU Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << U[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nUnknowns:\n";
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }

    return 0;
}
