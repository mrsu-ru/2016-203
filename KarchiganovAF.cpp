#include <math.h>
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
	float S1 = 0;
	float S2 = 0;
	float ten_9 = pow(10, 9);
	for (uint32_t i = 1; i <= ten_9; i ++) S1 += 1. / i / i;
	for (uint32_t i = ten_9; i >= 1; i --) S2 += 1. / i / i;
	cout << "S1=" << S1 << endl;
	cout << "S2=" << S2 << endl;
	return 0;
}