#include <iostream>

using namespace std;
long int s;

int main() {
  for (long int i = 1; i <= 1000000000; i++)
  {
    i = i + 1;
    s = s + i;
    return s;
  }
  cout << s;
  return 0;
}
