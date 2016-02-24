#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  long int s;
  s = 0;

  for (long int i = 1; i < pow(10,9); i++)
  {
    s = s + i;
  }
  cout << s << endl;
}
