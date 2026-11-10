//newton divided difference
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double x[20], y[20], dd[20][20];
    double value, result, term;
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
        dd[i][0] = y[i];
    // Construct divided difference table
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; i++){
            dd[i][j] =(dd[i + 1][j - 1] - dd[i][j - 1])   / (x[i + j] - x[i]);
        }
    }
    // Print divided difference table
    cout << "\nDivided Difference Table:\n\n";
    for (int i = 0; i < n; i++){
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; j++){
            cout << setw(12) << fixed << setprecision(4)
                 << dd[i][j];
        }
        cout << endl;
    }
    // Input required x
    cout << "\nEnter value of x to find y: ";
    cin >> value;
    // Calculate interpolation
    result = dd[0][0];
    term = 1;
    for (int i = 1; i < n; i++){
        term = term * (value - x[i - 1]);
        result = result + dd[0][i] * term;
    }
    // Print polynomial
    cout << "\nNewton Divided Difference Polynomial:\n";
    cout << "P(x) = " << dd[0][0];
    for (int i = 1; i < n; i++){
        cout << " + (" << dd[0][i] << ")";
        for (int j = 0; j < i; j++){
            cout << "(x - " << x[j] << ")";
        }
    }
    cout << endl;
    // Print result
    cout << "\nInterpolated value at x = "
         << value << " is: "
         << result << endl;
    return 0;
}