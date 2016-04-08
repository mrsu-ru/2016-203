#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    int n;
    setlocale(0,"");
    ifstream fin("Polkin(lab1).txt");
    fin>>n;
    double a[n][n],a1[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             fin>>a[i][j];
double x[n],b[n];double z;

    for(int i=0;i<n;i++)
       fin>>b[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
           a1[i][j]=a[i][j];

    for(int k=0;k<n;k++)
       for(int i=k+1;i<n;i++){

          b[i]=b[i]-b[k]*a[i][k]/a[k][k];
          for(int j=n-1; j>=0;j--)
             a[i][j]=a[i][j]-a[k][j]*a[i][k]/a[k][k];
             }




    for(int i=n-1;i>=0;i--)
        {
          z=0;

          for(int j=i+1;j<n;j++)
              z=z+a[i][j]*x[j];

          x[i]=(1.0/a[i][i])*(b[i]-z);
        }
        cout<<"Triangle Matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
             cout<<a[i][j]<<" ";
             cout<<endl;
    }
    for(int i=0;i<n;i++)cout<<b[i]<<endl;
  cout<<endl;
  cout<<"Otvet:";
    for(int i=0;i<n;i++)cout<<x[i]<<endl;
        fin.close();
    return 0;
}
