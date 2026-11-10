#include <bits/stdc++.h>
using namespace std;
double f(double x){
    return x * x * x - x - 2;
}
int main(){
    double x0, x1, x2, E;
    int iteration = 0;
    cout << "Enter initial value x0: ";
    cin >> x0;
    cout << "Enter initial value x1: ";
    cin >> x1;
    cout << "Enter error limit E: ";
    cin >> E;
    while (true){
        // Secant formula
        if (f(x1) - f(x0) == 0) {
            cout << "Division by zero!\n";
            break;
        }
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        iteration++;
        cout << "Iteration " << iteration<< ": x = "<< fixed << setprecision(6) << x2 << endl;
        // Stopping condition
        if (fabs(x2 - x1) < E){
            cout << "\nApproximate Root = " << x2 << endl;
    cout << "Number of Iterations = "<< iteration << endl;
            break;
        }
        // Update values
        x0 = x1;
        x1 = x2;
    }
    return 0;
}