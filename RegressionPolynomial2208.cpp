//Regression Polynomial
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n;// number of data points
    cin >> m;// degree of polynomial
    double x[100], y[100];
    double A[20][21] = {0};
    // Input data
    for (int i = 0; i < n; i++) {
        cin >>x[i];
    }
     for (int i = 0; i < n; i++) {
        cin >>y[i];
    }
    // Construct normal-equation augmented matrix
    for (int row = 0; row <= m; row++) {
        // Left side: sum(x^(row+col))
        for (int col = 0; col <= m; col++) {
            double sum = 0;
            for (int i = 0; i < n; i++) {
                sum += pow(x[i], row + col);
            }
            A[row][col] = sum;
        }
        // Right side: sum(x^row * y)
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pow(x[i], row) * y[i];
        }
        A[row][m + 1] = sum;
    }
    // Gauss-Jordan elimination
    for (int i = 0; i <= m; i++) {
        double pivot = A[i][i];
        // pivot er row borabor pivot diye divide,so pivot=1
        for (int j = i; j <= m + 1; j++) {
            A[i][j] /= pivot;
        }
        // Make other elements in this column = 0
        for (int k = 0; k <= m; k++) {
            if (k != i) {//pivot chara baki shob zero
                double factor = A[k][i];
                for (int j = i; j <= m + 1; j++) {//as operation amra row-wise chalai
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    // Coefficients
    double coef[20];
    for (int i = 0; i <= m; i++) {
        coef[i] = A[i][m + 1];
    }
    cout << fixed << setprecision(4);
    for (int i = 0; i <= m; i++) {
        cout << "a" << i << " = " << coef[i] << endl;
    }
    // Display equation
    cout << "Regression equation: y = ";
    for (int i = 0; i <= m; i++) {
        if (i == 0)
            cout << coef[i];
        else
            cout << " + " << coef[i] << "x^" << i;
    }

    cout << endl;

    // Prediction
    double value;
    cin >> value;
    double predictedY = 0;
    for (int i = 0; i <= m; i++) {
        predictedY += coef[i] * pow(value, i);
    }
    cout << "Predicted y = " << predictedY << endl;

    return 0;
}
/*input
5 2
1 2 3 4 5
6 11 18 27 38*/