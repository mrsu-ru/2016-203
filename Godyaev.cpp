#include <iostream>
#include<cmath>
using namespace std;

int main()
{
  float sum=0;
  for (double i=1;i<pow(10,5);i+=1){
    sum=sum+1/(i*i);
    //cout<<i<<" ";
    }  cout<<sum<<endl;
    sum=0;
    for (double i=pow(10,9);i>0;i-=1)
            sum=sum+1/(i*i);
  cout<<sum<<endl;


   return 0;
}
