#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float S,ss,i;


     i = 1;
     while(i<=pow(10,9))
     {
        S = S + 1.0/(pow(i,2));
        i = i + 1;
     }
        cout<<"1 = "<<S<<endl;



    i = pow(10,9);
     while(i>=1)
     {
        ss = ss + 1.0/(pow(i,2));
       i = i - 1;
     }
        cout<<"2 = "<<ss;

    return 0;
}
