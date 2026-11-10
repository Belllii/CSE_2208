#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x*x*x - 6*x*x + 11*x - 6;
}

double df(double x)
{
    return 3*x*x - 12*x + 11;
}

void newton(double xn, double E)
{
    double xn1;
    int it = 0;

    while(true)
    {
        it++;
        if(fabs(df(xn)) < 1e-12)
        {
            cout << "Derivative is 0\n";
            return;
        }
        // Newton-Raphson formula
        xn1 = xn - f(xn) / df(xn);
        // Stopping condition
        if(fabs(xn1 - xn) < E)
        {
            cout << "Iteration = " << it
                 << "   Root = " << xn1 << endl;

            return;
        }
        xn = xn1;
    }
}

int main(){
    double a, b, E = 0.0001;
    double step;
    cin >> a >> b >> step;
    int rootC = 0;
    double x1 = a;
    double x2 = x1 + step;
    while(x2 <= b && rootC < 3){
        // Check whether there is a root in this interval
        if(f(x1)*f(x2) < 0){
            cout << "Interval: ("
                 << x1 << ", "
                 << x2 << ")\n";
            // Use midpoint as initial guess
            double initial = (x1 + x2) / 2.0;

            newton(initial, E);

            rootC++;
        }

        // Move to the next interval
        x1 = x2;
        x2 += step;
    }

    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return (pow(x,4)-13*x*x+36);
}
double df(double x){
    return (4*pow(x,3)-26*x);
}
void newton(double xn,double E){
     double xn1=0;
    while(true){
        if(df(xn)==0){
            cout<<"Derivative 0\n";
            return;
        }
        xn1=xn-f(xn)/df(xn);
        if(fabs(xn1-xn)<E){
            cout<<xn1<<endl;
            return;
        }
        xn=xn1;
    }
}
int main(){
double E=0.0001;
int rootC=0;
double an=1,an_1=0,an_2=-13;
    double xmax=fabs(sqrt(pow(an_2/an,2)-2*(an_2/an)));
    cout<<"xmax="<<xmax<<"search interval= ("<<-xmax<<","<<xmax<<")\n";
double x1=-xmax;
double x2=x1+0.5;
while(x2<=xmax && rootC<4){
    if (f(x1)*f(x2)<0){
          cout<<"interval=("<<x1<<","<<x2<<")\n";
      cout<<"root:"<<rootC<<"   ";
       // midpoint is used as starting value
            double initial = (x1 + x2) / 2.0;

            newton(initial, E);
    rootC++;
    }
         
    x1=x2;
    x2+=0.5;
}

    return 0;
}*
/*#include<bits/stdc++.h>
using namespace std;
double f(double x){
return (x*x*x*x-10*x*x+9);
}
double df(double x){
    return (4*x*x*x-20*x);
}
void Newton(double x1,double E){
   int it=0;
   double xn=x1,xn1=0;
while(true){
    if(df(xn)==0){
        cout<<"derivative 0\n";
        return;
    }
    it++;
    xn1=xn-(f(xn)/df(xn));
    if(fabs(xn1-xn)<E){
        cout<<"the approx root="<<xn1<<"   no of it="<<it<<endl<<endl;
        break;
    }
    xn=xn1;
}
}
int main(){
    double an=1,an_1=0,an_2=-10;
    double xmax=fabs(sqrt(pow(an_2/an,2)-2*(an_2/an)));
    cout<<"xmax="<<xmax<<"search interval= ("<<-xmax<<","<<xmax<<")\n";
   double step=0.5;
    double x1=-xmax;
double x2=x1+step;
double E=0.00001;
int rootC=0;
while(x2<=xmax && rootC<4){

    if(f(x1)*f(x2)<0){
        cout<<"Bracket:"<<rootC+1<<"  ("<<x1<<","<<x2<<")\n";
      Newton(x1,E);
   rootC++;
    }
      x1=x2;
      x2+=step;
}
return 0;
}
*/
/*-------Gauss Seidel--------
 10x+y+z=12
2x+10y+z=13
2x+2y+10z=14
E=0.0001 Ans:1,1,1
#include<bits/stdc++.h>
using namespace std;
int main(){
double ox=0,oy=0,oz=0,i=0;
double E;
cin>>E;
double x=0,y=0,z=0;
while(true){
x=(12-y-z)/10;
y=(13-2*x-z)/10;
z=(14-2*x-2*y)/10;
i++;
 cout<<i<<"   "<<"x="<<x<<"  y="<<y<<"  z="<<z<<endl;
double maxe = max({fabs(ox-x),fabs(oy-y),fabs(oz-z)});
 ox=x;
oy=y;
oz=z;
if(maxe<E)
 break;
}
cout<<"the roots are:"<<"x="<<x<<"  y="<<y<<"  z="<<z;
return 0;
}*/
/* 10x+y+z=12
2x+10y+z=13
2x+2y+10z=14
E=0.0001 Ans:1,1,1  -----Jacobi-----
#include<bits/stdc++.h>
using namespace std;
int main(){
double x=0,y=0,z=0,i=0;
double E;
cin>>E;
double nx,ny,nz;
while(true){
nx=(12-y-z)/10;
ny=(13-2*x-z)/10;
nz=(14-2*x-2*y)/10;
i++;
 cout<<i<<"   "<<"x="<<x<<"  y="<<y<<"  z="<<z<<endl;
double maxe = max({fabs(nx-x),fabs(ny-y),fabs(nz-z)});
 x=nx;
y=ny;
z=nz;
if(maxe<E)
 break;
}
cout<<"the roots are:"<<"x="<<x<<"  y="<<y<<"  z="<<z;
return 0;
}*/
/*------1|Bisection----
#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return pow(x,3)-x-2;
}
void Bisection(double x1,double x2,double E){
           double x0;
    while(true){
         x0=(x1+x2)/2.0;
         cout<<"x1="<<x1<<"x2"<<x2<<"    "<<"x0="<<x0<<"f(x0)="<<f(x0)<<endl;
        if(f(x1)*f(x2)>=0){
            cout<<"Invalid Interval\n";
            return;
        }
     if(f(x0)==0) break;
     if(f(x0)*f(x1)<0){
        x2=x0;
     }
     else if(f(x0)*f(x2)<0) {
        x1=x0;
     }

     if(fabs((x2-x1)/x2)<E) break;
}
    cout<<"The final root is:"<<x0<<endl;
}
int main(){
double x1,x2,E;
cin>>x1>>x2>>E;
Bisection(x1,x2,E);
return 0;
}*/