//Crout
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
    // Crout LU Decomposition
    for(int i = 0; i < n; i++) {
        // Calculate L
        for(int k = i; k < n; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++) {
                sum += L[k][j] * U[j][i];
            }
            L[k][i] = A[k][i] - sum;
        }

        // Calculate U
        U[i][i] = 1;
        for(int k = i + 1; k < n; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            // if(L[i][i] == 0) {
            //     cout << "Cannot solve: zero pivot.\n";
            //     return 0;
            // }
            U[i][k] = (A[i][k] - sum) / L[i][i];
        }
    }
    // Forward substitution: LY = B
    for(int i = 0; i < n; i++) {
        double sum = 0;
        for(int j = 0; j < i; j++) {
            sum += L[i][j] * Y[j];
        }
        // if(L[i][i] == 0) {
        //     cout << "Cannot solve: zero pivot.\n";
        //     return 0;
        // }
        Y[i] = (B[i] - sum) / L[i][i];
    }
    // Backward substitution: UX = Y
    for(int i = n - 1; i >= 0; i--) {
        double sum = 0;

        for(int j = i + 1; j < n; j++) {
            sum += U[i][j] * X[j];
        }

        X[i] = Y[i] - sum;
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

    cout << "\nVerification:\n";

for(int i = 0; i < n; i++) {
    double sum = 0;

    for(int j = 0; j < n; j++) {
        sum += A[i][j] * X[j];
    }

    cout << "Equation " << i + 1 << ": "
         << sum << " = " << B[i];

    if(fabs(sum - B[i]) < 1e-6)
        cout << "  Verified";
    else
        cout << "  Not Verified";

    cout << endl;
}
    return 0;
}
