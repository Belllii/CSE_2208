/*Question:
Given the polynomial equation:
x^4-5x^2+4=0
Find all 4 roots of equation (i) using the Bisection or False Position method. 
The search interval is (-|x_max|,|x_max|), where (|x_max|) is given by equation (ii).
|x_{\max}|=sqrt{{a_(n-1)/a_n}^2 - 2*{a_(n-2)/a_n} } {ii}

(a) Find out the coefficients of equation (i).
Hint: Compare equation (i) with the standard polynomial equation:
a_nx^n + a_{n-1}x^{n-1}+ ..... +a_1x + a_0=0    {iii}
(b) Find the 4 brackets in the search interval for the 4 roots. Choose the step size =0.5
Print the 4 roots and the number of iterations needed for each root.
(c) Print the 4 roots. For each root, continue the loop until
|x_2-x_1|<E,where E=10^-4  */
#include <bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x*x*x - 5*x*x + 4;
}
void falsePosition(double x1, double x2, double E){
    double xOld = x1;
    double x0;
    int iteration = 0;
    while (true) {
        x0 =x1 - f(x1) * (x2 - x1) / (f(x2) - f(x1));
        iteration++;
        if (fabs(x0 - xOld) < E)
            break;

        if (f(x1) * f(x0) < 0){
            x2 = x0;
        }
    else  x1 = x0;

        xOld = x0;
    }
    cout << "Root = " << fixed << setprecision(6) << x0 << "   Iterations = " << iteration << endl;
}
int main(){
    double an = 1;      // a4
    double an_1 = 0;    // a3
    double an_2 = -5;   // a2
    double xmax = sqrt(pow(an_1 / an, 2)- 2 * (an_2 / an));
    cout << fixed << setprecision(6);
    cout << "xmax = " << xmax << endl;
    cout << "Search interval = ("<< -xmax << ", " << xmax << ")\n";
    double step = 0.5;
    double E = 1e-4;
    double x1 = -xmax;
    double x2 = x1 + step;
    int rootCount = 0;
    while (x2 <= xmax && rootCount < 4){
        if (fabs(f(x1)) < E) {
    cout << "Bracket " << rootCount + 1<< ": Root found at " << x1 << endl; 
    cout << "Root = " << x1 << "\tIterations = 0\n";
            rootCount++;
        }
 // If sign changes, a root is inside the bracket
        else if (f(x1) * f(x2) < 0) {
    cout << "Bracket " << rootCount + 1<< ": [" << x1 << ", " << x2 << "]" << endl;
            falsePosition(x1, x2, E);
            cout << endl;
         rootCount++;
        }
        x1 = x2;
        x2 += step;
    }
    return 0;
}
                          
                 //<----- Dynamic input ----->
                 
#include <bits/stdc++.h>
using namespace std;
double f(vector<double>& c, double x) {
    double result = 0;
    for (double a : c)
        result = result * x + a;
    return result;
}
double bisection(vector<double>& c, double a, double b,
                 double E, int& iterations) {
    iterations = 0;
    while (fabs(b - a) >= E) {
        double x0 = (a + b) / 2.0;
        iterations++;
        double fm = f(c, x0);
        if (fabs(fm) < 1e-12)
            return x0;
        if (f(c, a) * fm < 0)
            b = x0;
        else
            a = x0;
    }
    return (a + b) / 2.0;
}
int main() {
    int n;
    cout << "Enter polynomial degree: ";
    cin >> n;
    if (n < 2) {
        cout << "Degree must be at least 2.\n";
        return 0;
    }
    vector<double> c(n + 1);
    cout << "Enter coefficients from highest to constant:\n";
    for (int i = 0; i <= n; i++)
        cin >> c[i];
    if (fabs(c[0]) < 1e-12) {
        cout << "Leading coefficient cannot be zero.\n";
        return 0;
    }
    double radicand = (c[1] * c[1]) / c[0] - 2.0 * (c[2] / c[0]);
    if (radicand < 0) {
        cout << "The given search-bound formula is not "
                "applicable to these coefficients.\n";
        return 0;
    }
    double xmax = sqrt(radicand);
    double step = 0.5;
    double E = 1e-4;
    cout << fixed << setprecision(6);
    cout << "Search interval: [" << -xmax<< ", " << xmax << "]\n";
    cout << "\nRoots and iterations:\n";
    double left = -xmax;
    int rootCount = 0;
    double lastRoot = NAN;
    while (left < xmax) {
        double right = min(left + step, xmax);
        double fl = f(c, left);
        double fr = f(c, right);
        if (fabs(fl) < 1e-10) {
            if (rootCount == 0 ||
                fabs(left - lastRoot) > 1e-5) {
                cout << "Root " << ++rootCount
                     << " = " << left
                     << ", Iterations = 0\n";
                lastRoot = left;
            }
        } else if (fl * fr < 0) {
            int iterations;
            double root = bisection(c, left, right,
                                    E, iterations);

            if (rootCount == 0 ||
                fabs(root - lastRoot) > 1e-5) {
                cout << "Root " << ++rootCount
                     << " = " << root
                     << ", Iterations = "
                     << iterations << '\n';
                lastRoot = root;
            }
        }

        left = right;
    }

    if (fabs(f(c, xmax)) < 1e-10 &&
        (rootCount == 0 ||
         fabs(xmax - lastRoot) > 1e-5)) {
        cout << "Root " << ++rootCount
             << " = " << xmax
             << ", Iterations = 0\n";
    }

    if (rootCount == 0)
        cout << "No sign-changing roots found.\n";

    return 0;
}
