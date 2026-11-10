#include <bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x*x - x - 2;
}
// Derivative f'(x)
double df(double x){
    return 3 * x * x - 1;
}
int main(){
    double a, b, E;
    double xn, xn1;
    int iteration = 0;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter stopping criterion E: ";
    cin >> E;
    // Check whether the interval contains a root
    if (f(a) * f(b) >= 0){
        cout << "Invalid interval. No sign change found.\n";
        return 0;
    }
    // Step 3: Assume x0 = a
    xn = a;
    while (true){
        // Check division by zero
        if (df(xn) == 0) {
            cout << "Derivative is zero. Method cannot continue.\n";
            break;
        }
        // Step 4: Calculate x(n+1)
        xn1 = xn - f(xn) / df(xn);
        iteration++;
        cout << "Iteration " << iteration<< ": x = " << fixed << setprecision(6)<< xn1 << endl;
        // Step 5: Stopping condition
        if (fabs(xn1 - xn) < E) {
            cout << "\nApproximate Root = "<< xn1 << endl;
            cout << "Number of Iterations = "<< iteration << endl;
            break;
        }
 // Set xn = x(n+1)
        xn = xn1;
    }
    return 0;
}
               
                 //<.....dynamic....>
#include <bits/stdc++.h>
using namespace std;

double f(vector<double> &c,double x){
    double res=0;
    for(double a:c)
        res=res*x+a;
    return res;
}

double df(vector<double> &c,double x){
    int n=c.size()-1;
    double res=0;

    for(int i=0;i<n;i++)
        res=res*x+c[i]*(n-i);

    return res;
}

double raphson(vector<double> &c,double E,double x1,int &it){
    double xn=0;
    it=0;

    while(it<1000){
        double d=df(c,x1);

        if(fabs(d)<1e-12)
            return NAN;

        xn=x1-f(c,x1)/d;
        it++;

        if(fabs(xn-x1)<E)
            return xn;

        x1=xn;
    }

    return NAN;
}

int main(){
    int n;
    cin>>n;

    vector<double> c(n+1);

    for(int i=0;i<=n;i++)
        cin>>c[i];

    double E=0.0001;

    double xmax=sqrt(pow(c[1]/c[0],2)-2*(c[2]/c[0]));

    vector<double> roots;

    for(double x1=-xmax;x1<=xmax;x1+=0.5){
        int it;

        double root=raphson(c,E,x1,it);

        if(!isfinite(root))
            continue;

        bool duplicate=false;

        for(double r:roots){
            if(fabs(root-r)<E){
                duplicate=true;
                break;
            }
        }

        if(!duplicate){
            roots.push_back(root);

            cout<<"Root "<<roots.size()
                <<" = "<<root
                <<" Iterations = "<<it<<endl;
        }

        if(roots.size()==n)
            break;
    }

    return 0;
}
