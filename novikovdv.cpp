#include <iostream>
#include <math.h>

using namespace std;

int main() {

int i;

double s1,s2;

s1 = s2 = 0;

for(i = 1; i <= pow(10.0,9); i++)
s1=s1+1.0/pow(i,2);

for(i = pow(10.0,9); i >= 1 ; i--)
s2=s2+1.0/pow(i,2);

cout<<s1<<" - "<<s2;

return 0;
}