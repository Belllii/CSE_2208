#include<bits/stdc++.h>
using namespace std;
int main(){
    // Initial values
    double x = 0, y = 0, z = 0;
    double oldX, oldY, oldZ;
    double E;
    cout << "Enter stopping criterion E: ";
    cin >> E;
    int iteration = 0;
    while (true)   {
        // Store previous values for error calculation
        oldX = x;
        oldY = y;
        oldZ = z;
        // Calculate x using old y and z
        x = (85 - 6 * y + z) / 27.0;
        // Immediately use NEW x
        y = (72 - 6 * x - 2 * z) / 15.0;
        // Immediately use NEW x and NEW y
        z = (110 - x - y) / 54.0;
        iteration++;
        cout << "Iteration " << iteration << ": ";
        cout << "x = " << x
             << "  y = " << y
             << "  z = " << z << endl;
        // Calculate error
        double error = max({fabs(x - oldX),fabs(y - oldY),fabs(z - oldZ)});
        // Stopping condition
        if (error < E)
            break;
        // Safety limit
        if (iteration >= 100)     {
           cout << "Maximum iterations reached." << endl;
            break;
        }
    }
    cout << "\nFinal Solution:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    return 0;
}