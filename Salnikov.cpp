#include "Salnikov.h"


/**
* Метод Гаусса
*/
void Salnikov::lab1()
{
	long double tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = A[i][i];
		if (tmp != 0) {
			for (int j = N; j >= i; j--) {
				A[i][j] /= tmp;
				b[j] /= tmp;
			}
		}
		for (int j = i + 1; j < N; j++)
		{
			tmp = A[j][i];
			if (tmp != 0) {
				for (int k = N; k >= i; k--)
					A[j][k] -= tmp*A[i][k];
				
			}
		}
	}

	x[N - 1] = b[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		x[i] = b[i];
		for (int j = i + 1; j < N; ++j)
			x[i] -= x[j] * A[i][j];
	}

}

void Salnikov::lab2()
{

}

void Salnikov::lab3()
{

}

void Salnikov::lab4()
{

}

void Salnikov::lab5()
{

}

void Salnikov::lab6()
{

}

void Salnikov::lab7()
{

}


