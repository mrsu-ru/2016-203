#include <iostream>
#include <math.h>
using namespace std;

main()
{
    setlocale (0,"");
    float s;
    for (float i=1; i<=pow(10,5); i+=1)
    {
        s=s+1/(i*i);
        //cout << s << " ";
    }

    cout << s << endl;
    s=0;

    for (float i=pow(10,8); i>0; i-=1)
    {
        s=s+1/(i*i);
        //cout << s << " ";
    }

    cout << s;
    s=0;

    return 0;
}
