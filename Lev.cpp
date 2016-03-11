#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main()
{
    float s,s1;
    s=0;
    s1=0;
    int step = pow(10,9);
    for(int i=1; i<=step; i++)
    {
      s=s+ 1.0/(i*i);
    }

    for(int i=step; i>=1; i--)
    {
      s1=s1+ 1.0/(i*i);
    }
    cout<<s<<"   "<<s1;


   // system("pause");

    return(0);
}
