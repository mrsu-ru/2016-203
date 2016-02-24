#include <iostream>
#include <cmath>
#define n 1000000000
using namespace std;

int main()
{
    double sum1 = 0, sum2 = 0;
    for (int i=1; i<=n; i++)
            sum1 +=1.0/(i*i);

    for(int i=n; i>0; i--)
            sum2 +=1.0/(i*i);
    cout<<fabs(sum2-sum1);
    return 0;
}
