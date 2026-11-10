#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;
    double A[10][10], L[10][10] = {0}, U[10][10] = {0};
    double B[10], Y[10], X[10];
    cout << "Enter augmented matrix [A|B]:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        // Calculate U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }
        // Calculate L
        L[i][i] = 1;
        for (int k = i + 1; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[k][j] * U[j][i];
            }
            if (fabs(U[i][i]) < 1e-9) {
                cout << "\nLU decomposition cannot be performed without pivoting.\n";
                return 0;
            }
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
    cout << "\nLower Triangular Matrix L:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << L[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nUpper Triangular Matrix U:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << U[i][j] << "\t";
        }
        cout << endl;
    }
    bool singular = false;
    for (int i = 0; i < n; i++) {
        if (fabs(U[i][i]) < 1e-9) {
            singular = true;
            break;
        }
    }
    if (singular) {
        cout << "\nSystem is singular.\n";
        cout << "It may have no solution or infinitely many solutions.\n";
        return 0;
    }
    // Forward substitution: LY = B
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * Y[j];
        }
        Y[i] = B[i] - sum;
    }
    // Back substitution: UX = Y
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }
    cout << "\nThe system has a UNIQUE solution.\n";
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }
    return 0;
}