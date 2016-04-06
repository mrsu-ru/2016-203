#include "nazarovvi.h"

/**
 * Метод Гаусса
 */
void nazarovvi::lab1()
{
    double coef = 0;
    for (int k=0; k<N-1; k++)
    {
        for (int i=k+1; i<N; i++)
        {
            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
            {
                A[i][j] -= coef*A[k][j];
               // if (abs(A[i][j])<1e-16) A[i][j] = 0;
            }
            b[i] -= coef*b[k];
        }
    }
    for(int i = 0; i<N; i++)
        x[i]=b[i];

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void nazarovvi::lab2()
{
    long double coef;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i;
        swap(A[maxn], A[k]);
        swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {

            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= coef*A[k][j];
            b[i] -= coef*b[k];
        }
    }


    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void nazarovvi::lab3()
{
	long double** L = new long double*[N];
    for (int i=0; i<N; i++)
        L[i] = new long double[N];
	long double* y = new long double[N];
	long double s=0;
	//зануляем матрицу Л
	for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            {
                L[i][j]=0;
            }
	//находим нижнетреугольную матрицу Л
	for (int k = 0; k < N; k++)
    {
        for(int i=0; i<k; i++)
            s+=L[k][i]*L[k][i];

        L[k][k]=sqrt(A[k][k]-s);
        s = 0;

        for(int i=k+1; i < N; i++)
        {
            for (int j=0; j<i-1; j++)
                s+=L[i][j]*L[k][j];

            L[i][k] = (A[i][k]-s)/L[k][k];
            s = 0;
        };
    }


	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

	//решаем первую систему
    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int k=0; k < i; k++)
			s += L[i][k]*y[k];

        y[i] = (b[i] - s)/L[i][i];
        s = 0;
    }
    //решаем вторую систему
	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int k=i+1;k<N;k++)
			s += L[k][i]*x[k];

        x[i] = (y[i] - s)/L[i][i];
        s = 0;
    }
    delete[] y;
}



/**
 * Метод прогонки
 */
void nazarovvi::lab4()
{
	long double* P = new long double[N];
    long double* Q = new long double[N];
    for (int i=0; i<N; i++)
    {
        P[i]=0;
        Q[i]=0;
    }

    P[0] = -A[0][1]/A[0][0];
    Q[0] = b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        P[i] = A[i][i+1]/(-A[i][i-1]*P[i-1]-A[i][i]);
        Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i-1]*P[i-1]-A[i][i]);
    }
    x[N-1] = Q[N-1];
    for(int i=N-2; i>=0; i--)
        x[i] = P[i]*x[i+1]+Q[i];
    delete[] P;
    delete[] Q;
}



/**
 * Метод Якоби
 */
void nazarovvi::lab5()
{
    long double eps = 0.0001;
    long double* y = new double[N];
	long double norm;
    do {
		for (int i = 0; i < N; i++)
        {
			y[i] = b[i];
			for (int j = 0; j < N; j++)
			{
				if (i != j)
					y[i] -= A[i][j] * x[j];
			}
			y[i] /= A[i][i];
		}
        norm = abs(x[0] - y[0]);
		for (int h = 0; h < N; h++)
        {
			if (abs(x[h] - y[h]) > norm)
				norm = abs(x[h] - y[h]);
			X[h] = y[h];
		}
	} while (norm > eps);
	delete[] y;

}



/**
 * Метод Зейделя
 */
void nazarovvi::lab6()
{

}



/**
 * Один из градиентных методов
 */
void nazarovvi::lab7()
{

}
