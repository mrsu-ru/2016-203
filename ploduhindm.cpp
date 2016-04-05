#include "ploduhindm.h"

/**
 * Метод Гаусса
 */
void ploduhindm::lab1()
{
    for (int i = 0; i < N; i++)
        x[i] = b[i];
     long double m;
     for (int k = 0; k < N-1; k++)
        {
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
 int ploduhindm::maxEl(long double* a, int x)
    {
        int tmp = x;
        for (int i=x+1; i<N; i++)
        {
            if (abs(a[i]) > abs(a[tmp])) tmp = i;
        }
        return tmp;
    }
void ploduhindm::lab2()
{
    for (int i = 0; i < N; i++)
        x[i] = b[i];
     long double m;
     long double* col = new long double[N];
     for (int k = 0; k < N-1; k++)
        {
            for (int i=0; i<N; i++)
            {
                col[i] = A[i][k];
            }
             if (maxEl(col,k) != k)
                {
                swap(A[maxEl(col,k)], A[k]);
                swap(x[maxEl(col,k)], x[k]);
                }
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
    delete[] col;
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ploduhindm::lab3()
{
    long double** L = new long double*[N];
    for (int i=0; i<N; i++)
        L[i] = new long double[N];
	long double* y = new long double[N];
	long double s=0;
	for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            {
                L[i][j]=0;
            }
	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i==j)
            {
               for(int k=0; k<i; k++)
                    s+=L[i][k]*L[i][k];
                L[i][i]=sqrt(A[i][i]-s);

                s = 0;
            }
            if (j<i)
            {
                for (int k=0; k<j; k++)
                    s+=L[i][k]*L[j][k];
                L[i][j] = (A[i][j]-s)/L[j][j];
                s = 0;
            }
        };
    }

	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int j=0; j < i; j++)
			s += L[i][j]*y[j];

        y[i] = (b[i] - s)/L[i][i];
        s = 0;
    }

	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s += L[j][i]*x[j];

        x[i] = (y[i] - s)/L[i][i];
        s = 0;
    }
    delete[] y;
    for(int i=0; i<N; i++)
        delete[] L[i];
    delete[] L;
}



/**
 * Метод прогонки
 */
void ploduhindm::lab4()
{
    long double* P = new long double[N];
    long double* Q = new long double[N];
    for (int i=0; i<N; i++)
    {
        P[i]=0;
        Q[i]=0;
    }

    P[0]=A[0][1]/(-A[0][0]);
    Q[0]=b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        P[i] = A[i][i+1]/(-A[i][i]-A[i][i-1]*P[i-1]);
        Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i]-A[i][i-1]*P[i-1]);
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
void ploduhindm::lab5()
{

}



/**
 * Метод Зейделя
 */
void ploduhindm::lab6()
{

}



/**
 * Один из градиентных методов
 */
void ploduhindm::lab7()
{

}
