#include <iostream>
#include <iomanip>
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
    // First column = y values
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];
    // Construct BACKWARD difference table
    for (int j = 1; j < n; j++){
        for (int i = j; i < n; i++){
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
    // Print backward difference table
    cout << "\nBackward Difference Table:\n\n";
    cout << setw(8) << "x"<< setw(12) << "y";
    for (int j = 1; j < n; j++){
        cout << setw(12) << "D" + to_string(j);
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << setw(8) << x[i];
        for (int j = 0; j <= i; j++){
            cout << setw(12) << diff[i][j];
        }
        cout << endl;
    }
    // Calculate h
    h = x[1] - x[0];
    // Input required x
    cout << "\nEnter value of x to find y: ";
    cin >> value;
    // Backward interpolation parameter
    u = (value - x[n - 1]) / h;
    // Print polynomial
    cout << "\nNewton Backward Polynomial:\n";
    cout << "P(x) = " << diff[n - 1][0];
    for (int i = 1; i < n; i++) {
        cout << " + (" << diff[n - 1][i] << ")";
        cout << "[u";
        for (int j = 1; j < i; j++) {
            cout << "(u + " << j << ")";
        }
        cout << "] / " << i << "!";
    }
    cout << "\n\nwhere:" << endl;
    cout << "u = (x - " << x[n - 1] << ") / " << h << endl;

    // Calculate interpolation
    result = diff[n - 1][0];

    double term = 1;

    for (int i = 1; i < n; i++){
        term = term * (u + (i - 1)) / i;

        result = result + term * diff[n - 1][i];
    }

    cout << "\nInterpolated value at x = "
         << value << " is: "
         << result << endl;

    return 0;
}