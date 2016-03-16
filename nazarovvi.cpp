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
 int nazarovvi::maxElemNum(long double* a, int c)
    {
        int tmp = c;
        for (int i=c+1; i<N; i++)
        {
            if (abs(a[i]) > abs(a[tmp])) tmp = i;
        }
        return tmp;
    }
void nazarovvi::lab2()
{
    long double coef;
    long double* column = new long double[N];

    for (int k=0; k<N-1; k++)
    {
        for (int i=0; i<N; i++)
            {
                column[i] = A[i][k];
            }
        if (maxElemNum(column,k) != k)
            {
                swap(A[maxElemNum(column,k)], A[k]);
                swap(b[maxElemNum(column,k)], b[k]);
            }
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

}



/**
 * Метод прогонки
 */
void nazarovvi::lab4()
{

}



/**
 * Метод Якоби
 */
void nazarovvi::lab5()
{

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
