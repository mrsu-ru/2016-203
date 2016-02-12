#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    double k=0,l=0;
    long z=pow(10,90);
    for(int i=1;i<=z;i++)
        k=k+1.0/pow(i,2);
    for(int j=z;j>=1;j--)
        l=l+1.0/pow(j,2);
    cout<<k<<endl<<l;
    return 0;
}
