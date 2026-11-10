#include <iostream>
#include <cmath>
using namespace std;
// Differential equation
double f(double x, double y) {
    return x + y;
}
int main() {
    double x0, y0, xn, h;
    double k1, k2, k3, k4;
    int n;
    cout << "Enter initial x: ";
    cin >> x0;

    cout << "Enter initial y: ";
    cin >> y0;

    cout << "Enter final x: ";
    cin >> xn;

    cout << "Enter number of steps: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of steps must be positive.";
        return 0;
    }

    h = (xn - x0) / n;
    for (int i = 0; i < n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x0 = x0 + h;
    }
    cout << "\nFinal value of y = " << y0 << endl;
return 0;
}
