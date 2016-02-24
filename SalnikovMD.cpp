#include <iostream>
#include <cmath>

using namespace std;

float calc(int bgn, int ed)
{
    float sum = 0;
    if (bgn < ed) {
        for (int i = bgn; i < ed; ++i)
            sum += 1.0/pow(i, 2);
    } else {
        for (int i = bgn; i > ed; --i)
            sum += 1.0/pow(i, 2);
    }
    return sum;
}

int main()
{
    cout << calc(pow(10, 9), 1);
    return 0;
}
