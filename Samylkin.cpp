#include "Samylkin.h"

/**
 * Метод Гаусса
 */
void Samylkin::lab1()
{
  for(int k=0; k<N; k++)
        for(int i=k+1; i<N;i++)
        {
           float p=A[i][k]/A[k][k];
            b[i]=b[i]-(b[k]*p);
            for(int j=0;j<N;j++)
                A[i][j]=A[i][j]-A[k][j]*(A[i][k]/A[k][k]);
        }


    double s=0;
    x[N-1]=b[N-1]/A[N-1][N-1];
    for(int i=N-1;i>=0;i--)
    {

        for (int j=i+1; j<N;j++)
            s=s+A[i][j]*x[j];
        x[i]=(b[i]-s)/A[i][i];
        s=0;

    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Samylkin::lab2()
{

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Samylkin::lab3()
{

}



/**
 * Метод прогонки
 */
void Samylkin::lab4()
{

}



/**
 * Метод Якоби
 */
void Samylkin::lab5()
{

}



/**
 * Метод Зейделя
 */
void Samylkin::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Samylkin::lab7()
{

}
