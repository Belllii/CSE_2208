#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double A[10][11];
    double ori[10][11];
    // Input augmented matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++) {
            cin >> A[i][j];
            ori[i][j]=A[i][j];
        }    
    }
    // Gauss-Jordan Elimination
    for(int i = 0; i < n; i++){
        // Make the pivot 1
        double pivot = A[i][i];
        for(int j = 0; j <= n; j++){
            A[i][j] = A[i][j] / pivot;
        }
        // Make all other elements in pivot column 0
        for(int k = 0; k < n; k++) {
            if(k != i) {
                double factor = A[k][i];
                for(int j = 0; j <= n; j++) {
                    A[k][j] = A[k][j] - factor * A[i][j];
                }
            }
        }
    }
    // Print Reduced Row Echelon Form
    cout << "Reduced Row Echelon Form:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    // Print solution
    cout << "\nSolution:\n";
    for(int i = 0; i < n; i++){
        cout << "x" << i + 1 << " = " << A[i][n] << endl;
    }
    // Verification
    cout << "\nVerification:\n";
    for(int i = 0; i < n; i++){
        double lhs = 0;
        // Substitute X values into original equation
        for(int j = 0; j < n; j++){
            lhs = lhs + ori[i][j] * A[j][n];
        }
        double rhs = ori[i][n];
        cout << "Equation " << i + 1 << ": "
             << fixed << setprecision(3)
             << lhs << " = " << rhs;
        if(abs(lhs - rhs) < 0.001) {
            cout << " -> Satisfied";
        }
        else{
            cout << " -> Not Satisfied";
        }
        cout << endl;
    }
    return 0;
}