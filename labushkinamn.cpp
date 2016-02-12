#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;
 int main()
 {
     float f,f1;
     float n;
     n=pow(10,9);
     f=0;f1=0;

     for (int i=1;n;i++)
        f=f+1.0/(i*i);
    cout<<"1)"<<f<<endl;

    for (int i=n;1;i--)
        f1=f1+1.0/(i*i);
    cout<<"2)"<<f1<<endl;

    return(0);
 }
