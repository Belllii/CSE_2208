#include <bits/stdc++.h>
using namespace std;
int main(){
    double x = 0, y = 0, z = 0;       // Initial values
    double newX, newY, newZ;
    double E;
    cout << "Enter stopping criterion E: ";
    cin >> E;
    int iteration = 0;
    while (true)   {
        // Calculate new values using OLD values
        newX = (85 - 6 * y + z) / 27.0;
        newY = (72 - 6 * x - 2 * z) / 15.0;
        newZ = (110 - x - y) / 54.0;
        iteration++;
        cout << "Iteration " << iteration << ": ";
        cout << "x = " << newX
             << "  y = " << newY
             << "  z = " << newZ << endl;

        // Calculate maximum error
        double error = max({
            fabs(newX - x),
            fabs(newY - y),
            fabs(newZ - z)
        });

        // Update old values
        x = newX;
        y = newY;
        z = newZ;

        // Stopping condition
        if (error < E)
            break;

        // Safety limit
        if (iteration >= 100)
        {
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