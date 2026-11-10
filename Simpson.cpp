//<-------------1/3 rd---------->
#include <bits/stdc++.h>
using namespace std;
// Function to integrate
double f(double x) {
    return 1 / (1 + x * x);
}
int main() {
    double a, b, h, sum = 0;
    int n;
    cout << "Enter lower limit: ";
    cin >> a;
    cout << "Enter upper limit: ";
    cin >> b;
    cout << "Enter number of intervals: ";
    cin >> n;
    if (n % 2 != 0 || n <= 0) {
        cout << "Number of intervals must be positive and even.";
        return 0;
    }
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double result = (h / 3) * sum;

    cout << "Integration result = " << result << endl;

    return 0;
}

//<-----------3/8th---------->

#include <iostream>
#include <cmath>
using namespace std;
// Function to integrate
double f(double x) {
    return 1 / (1 + x * x);
}
int main() {
    double a, b, h, sum = 0;
    int n;
    cout << "Enter lower limit: ";
    cin >> a;
    cout << "Enter upper limit: ";
    cin >> b;
    cout << "Enter number of intervals: ";
    cin >> n;
    if (n <= 0 || n % 3 != 0) {
        cout << "Number of intervals must be a positive multiple of 3.";
        return 0;
    }
    h = (b - a) / n;
    sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;

        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    double result = (3 * h / 8) * sum;

    cout << "Integration result = " << result << endl;

    return 0;
}
