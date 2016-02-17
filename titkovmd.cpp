#include <iostream>

using namespace std;

int main()
{
double sum1,sum2;

for (double i=1.e9; i>0; i-=1.0)
    sum2 = sum2 + 1.0/(i*i);

for (double i=1; i<=1.e9; i+=1.0)
    sum1 = sum1 + 1.0/(i*i);

    cout << sum1;
    cout << endl;
    cout << sum2;
    return 0;

}

