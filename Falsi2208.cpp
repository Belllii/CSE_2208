#include <bits/stdc++.h>
using namespace std;
double f(double x){
    return 3 * x - cos(x) - 1;
}
void falsePosition(double x1, double x2, double E){
    // Step 1: Check the initial interval
    if (f(x1) * f(x2) >= 0)  {
        cout << "Invalid interval!" << endl;
        return;
    }
    double x0;
    while(true){
        // Step 2: Calculate estimated root
        x0 = x1 - f(x1) * (x2 - x1) / (f(x2) - f(x1));
        // Step 3: Find f(x0)
        double fx0 = f(x0);
        cout << "x1 = " << x1
             << ", x2 = " << x2
             << ", x0 = " << x0
             << ", f(x0) = " << fx0 << endl;
        // Step 4: If f(x0) = 0, root found
        if (fx0 == 0)       {
            break;
        }
        // If f(x0) * f(x1) < 0
        if (f(x0) * f(x1) < 0)      {
            x2 = x0;
        }
        // If f(x0) * f(x2) < 0
        else if (f(x0) * f(x2) < 0)    {
            x1 = x0;
        }
        // Stopping criterion
        if (fabs((x2 - x1) / x2) < E)      {
            break;
        }
    }
    cout << "\nFalse Position Root = " << x0 << endl;
}
int main(){
    double x1, x2, E;
    cout << "Enter x1, x2 and stopping criterion E: ";
    cin >> x1 >> x2 >> E;
    falsePosition(x1, x2, E);
    return 0;
}
