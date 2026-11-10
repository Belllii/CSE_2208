#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double x[20], y[20], diff[20][20];
    double value, h, u, result;
    // Input
    cout << "Enter number of data points: ";
    cin >> n;
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i];
    // First column
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];
    // Forward difference table
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; i++){
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }
    // Print difference table
    cout << "\nDifference Table:\n\n";
    for (int i = 0; i < n; i++){
        cout << setw(8) << x[i];
        for (int j = 0; j < n - i; j++){
            cout << setw(12) << diff[i][j];
        }
        cout << endl;
    }
    // Calculate h and u
    h = x[1] - x[0];
    cout << "\nEnter value of x to find y: ";
    cin >> value;
    u = (value - x[0]) / h;
    // Print Newton Forward Polynomial
    cout << "\nNewton Forward Polynomial:\n";
    cout << "P(x) = " << diff[0][0];
    for (int i = 1; i < n; i++){
        cout << " + (" << diff[0][i] << ")";
        for (int j = 0; j < i; j++){
            cout << "(u";
            if (j > 0)
                cout << " - " << j;
            cout << ")";
        }
        cout << " / " << i << "!";
    }
    cout << "\nwhere u = (x - " << x[0] << ") / " << h << endl;
    // Calculate result
    result = diff[0][0];
    double term = 1;
    for (int i = 1; i < n; i++){
        term = term * (u - (i - 1)) / i;
        result = result + term * diff[0][i];
    }
    cout << "\nInterpolated value at x = "
         << value << " is " << result << endl;
    return 0;
}