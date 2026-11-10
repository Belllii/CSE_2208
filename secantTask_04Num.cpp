//<-----secant---->>
#include <bits/stdc++.h>
using namespace std;
double f(vector<double> a, double x){
    double result = 0;
    for(double c:a) {
        result = result * x + c;
    }
    return result;
}
void printEquation(vector<double> a, int n){
    cout << "Equation: ";
    for(int i = 0; i <= n; i++){
        double c = a[i];
        int power = n - i;
        if(i > 0 && c >= 0)
            cout << "+";
        if(power == 0)
            cout << c;
        else if(power == 1)
            cout << c << "x";
        else
            cout << c << "x^" << power;
    }
    cout << " = 0\n";
}
void secant(vector<double> a, int n,double x0, double x1, double E){
    double x2;
    int it = 0;
    while(true) {
        if(fabs(f(a,x1) - f(a,x0)) < 1e-12) {
            cout << "Division by zero\n";
            return;
        }
        x2 = x1 - f(a,x1) * (x1 - x0) / (f(a,x1) - f(a,x0));
        it++;
        if(fabs(x2 - x1) < E){
            cout << "Root = " << fixed << setprecision(6)<< x2 << "   Iterations = " << it << endl;
            return;
        }
        x0 = x1;
        x1 = x2;
    }
}
int main(){
    int n;
    cout << "Enter degree: ";
    cin >> n;
    vector<double> a(n + 1);
    cout << "Enter coefficients:\n";
    for(int i = 0; i <= n; i++)
        cin >> a[i];
    printEquation(a, n);
    double maximum = 0;
    for(int i = 1; i <= n; i++) {
        maximum = max(maximum, fabs(a[i] / a[0]));
    }
    double xmax = 1 + maximum;
    double step = 0.45;
    double E = 0.001;
    cout << "xmax = " << xmax << endl;
    cout << "Search interval = ("<< -xmax << ", " << xmax << ")\n";
    double x1 = -xmax;
    double x2 = x1 + step;
    int rootCount = 0;
    while(x2 <= xmax && rootCount < n){
        if(f(a,x1) * f(a,x2) < 0) {
            rootCount++;
            cout << "Root " << rootCount << endl;
            cout << "Bracket = ["<< x1 << ", " << x2 << "]\n";
            secant(a,n,x1,x2,E);
            cout << endl;
        }
        x1 = x2;
        x2 += step;
    }
    return 0;
}
//<-------using newton raphson------>
/*#include <bits/stdc++.h>
using namespace std;
double f(vector<double> a, double x) {
    double result = 0;
    for(double c : a)
        result = result * x + c;
    return result;
}
double df(vector<double> a, double x) {
    int n = a.size() - 1;
    double result = 0;
    for(int i = 0; i < n; i++)
        result = result * x + a[i] * (n - i);//Horner's method apply korlei 
                       //hoye jay just coeficent gula determine krte hoy as derivative 
    return result;
}
void newtonRaphson(vector<double> a, double x, double E) {
    int it = 0;
    while(it < 1000) {
        double derivative = df(a, x);
        if(fabs(derivative) < 1e-12) {
            cout << "Derivative is zero. Try another initial guess.\n";
            return;
        }
        double xnew = x - f(a, x) / derivative;
        it++;
        if(fabs(xnew - x) < E) {
            cout << fixed << setprecision(6);
            cout << "Root = " << xnew;
            cout << "  Iterations = " << it << endl;
            return;
        }
        x = xnew;
    }
    cout << "Method did not converge.\n";
}
int main() {
    int n;
    cout << "Enter degree: ";
    cin >> n;
    vector<double> a(n + 1);
    cout << "Enter coefficients from highest power to constant:\n";
    for(int i = 0; i <= n; i++)
        cin >> a[i];
    if(a[0] == 0) {
        cout << "Leading coefficient cannot be zero.\n";
        return 0;
    }
    double x, E = 0.001;
    cout << "Enter initial guess: ";
    cin >> x;
    newtonRaphson(a, x, E);
    return 0;
}*/


