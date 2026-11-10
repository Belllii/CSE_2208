//Gauss Elimination
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double a[10][11], x[10];
    cout << "Enter number of equations: ";
    cin >> n;
    cout << "Enter the augmented matrix:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            cin >> a[i][j];
        }
    }
    // Forward Elimination
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            double factor = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++){
                a[j][k] = a[j][k] - factor * a[i][k];
            }
        }
    }
// Back Substitution
   for(int i=n-1;i>=0;i--){
  double sum=0;
  for(int j=i+1;j<n;j++){
  sum+=a[i][j]*x[j];
  }
  x[i]=(a[i][n]-sum)/a[i][i];
}
    cout<<"Echelon Form\n";
for(int i=0;i<n;i++){
    for(int j=0;j<n+1;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
    }
    // Display solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++){
        cout << "x" << i + 1 << " = "<< fixed << setprecision(4) << x[i] << endl;
    }
    return 0;
}