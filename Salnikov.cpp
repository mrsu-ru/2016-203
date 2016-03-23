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

int Salnikov::maxElemNum(double* a, int c)
{
	int tmp = c;
	for (int i=c+1; i<N; i++) {
		if (abs(a[i]) > abs(a[tmp])) 
			tmp = i;
    }
	return tmp;
}
void Salnikov::lab2()
{
    double coef;
    double* column = new double[N];

    for (int k=0; k < N-1; k++)
    {
        for (int i=0; i<N; i++) {
            column[i] = A[i][k];
        }
		int tmp_max_el_num = maxElemNum(column, k); //находим индекс максимального элемента в столбце
		if (tmp_max_el_num != k) {
            std::swap(A[tmp_max_el_num], A[k]);
            std::swap(b[tmp_max_el_num], b[k]);
        }
        for (int i=k+1; i<N; i++) {

            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= coef*A[k][j];
            b[i] -= coef*b[k];
        }

    }

    for(int i = 0; i<N; i++) {
        x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--) {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];

    }
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


int main()
{
	Salnikov frst;
	frst.read_file();
	frst.run(2);
	frst.write_result();

	return 0;
}