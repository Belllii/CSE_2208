#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double x[100], y[100];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double sumX = 0, sumY = 0;
    double sumXY = 0, sumX2 = 0;
    // Calculate required sums
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    // Calculate b
    double b = (n * sumXY - sumX * sumY)/(n * sumX2 - sumX * sumX);
    // Calculate a
    double a = (sumY - b * sumX) / n;
    cout << fixed << setprecision(4);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Regression equation: ";
    cout << "y = " << a << " + " << b << "x" << endl;
    // Prediction
    double value;
    cout << "\nEnter x value for prediction: ";
    cin >> value;
    double predictedY = a + b * value;
    cout << "Predicted y = " << predictedY << endl;
    return 0;
}
/*5
1 35
2 40
3 50
4 55
5 65
6*/