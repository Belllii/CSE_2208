//1)T=a+be^(t/4)
#include <bits/stdc++.h>
using namespace std;
int main() {
 int n;
 cin>>n;
 double x[20],X[20],Y[20],b=0,a=0;
 double sumX=0,sumY=0,sumXY=0,sumX2=0;
 for(int i=0;i<n;i++){
     cin>>x[i];
     X[i]=exp(x[i]/4);
 }
   for(int i=0;i<n;i++){
     cin>>Y[i];
 }
 
 for(int i=0;i<n;i++){
 sumX+=X[i];
 sumY+=Y[i];
 sumXY+=X[i]*Y[i];
 sumX2+=X[i]*X[i];
 }
b=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
a=(sumY-b*sumX)/n;
cout<<fixed<<setprecision(3);
cout<<"a="<<a<<"   b="<<b<<endl;
cout<<"equ: T="<<a<<"+"<<b<<"e^(t/4)"<<endl;
double res=a+b*exp(6.0/4);//integer division must be avoided
cout<<"value at t=6  :"<<res<<endl;
    return 0;
}
/*5
1 2 3 4 5
50 80 96 120 145*/
//2)y=ax^b
#include <bits/stdc++.h>
using namespace std;
int main() {
 int n;
 cin>>n;
 double x[20],y[20],X[20],Y[20],A=0,b=0,a=0;
 double sumX=0,sumY=0,sumXY=0,sumX2=0;
 for(int i=0;i<n;i++){
     cin>>x[i];
     X[i]=log(x[i]);
 }
   for(int i=0;i<n;i++){
     cin>>y[i];
     Y[i]=log(y[i]);
 }
 for(int i=0;i<n;i++){
 sumX+=X[i];
 sumY+=Y[i];
 sumXY+=X[i]*Y[i];
 sumX2+=X[i]*X[i];
 }
b=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
A=(sumY-b*sumX)/n;
a=exp(A);
cout<<fixed<<setprecision(3);
cout<<"a="<<a<<"   b="<<b<<endl;
cout<<"equ:"<<a<<"x^"<<b<<endl;
    return 0;
}
//3)y=ae^bx
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double x[100], y[100];
    double Y[100];
    double sumX = 0;
    double sumY = 0;
    double sumX2 = 0;
    double sumXY = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        Y[i] = log(y[i]);
        sumX += x[i];
        sumY += Y[i];
        sumX2 += x[i] * x[i];
        sumXY += x[i] * Y[i];
    }
    // Linear regression: Y = A + bx
    double b = (n * sumXY - sumX * sumY)/(n * sumX2 - sumX * sumX);
    double A = (sumY - b * sumX) / n;
    // A = ln(a)
    double a = exp(A);
    cout << fixed << setprecision(4);
    cout << "A = " << A << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Regression equation: ";
    cout << "y = " << a << " * e^(" << b << "x)" << endl;

    return 0;
}
/*4
1 2.7
2 7.4
3 20.1
4 54.6*/