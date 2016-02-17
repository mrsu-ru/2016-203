#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float s=0,x;
    for (int i=1; i<=pow(10,9);i++)
    {
       x=i;
       s+=(1.0/(x*x));
    }

    cout << s << endl;
    s=0;
    for (int i=pow(10,9);i>=1;i--)
     {
       x=i;
       s+=(1.0/(x*x));
    }
    cout << s;
    return 0;
}
