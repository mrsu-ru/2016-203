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
                swap(b[maxEl(col,k)], b[k]);
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
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ploduhindm::lab3()
{

}



/**
 * Метод прогонки
 */
void ploduhindm::lab4()
{

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
