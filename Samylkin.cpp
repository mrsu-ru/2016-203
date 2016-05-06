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
    int k=0,h=A[0][0];
    for (int i=0; i<N; i++)
    {

            if (h<A[i][0])
            {
                h=A[i][0];
                k=i;
            }
    }
    if (k!=0)
        for (int j=0; j<N; j++)
        {
        std::swap(A[0][j],A[k][j]);
        }
        int p=0,t=0;
        float y;
        while (p<N)
        {

            for (int i=p+1; i<N; i++)
            {
                 y=-A[i][t];
                 for (int j=t; j<N; j++)
                 {
                      A[i][j]=A[i][j]+A[p][j]/A[p][t]*(y);

                 }
                 b[i]=b[i]+b[p]/A[p][t]*(y);
            }
            p++;
            t++;
        }
        t=N-1;
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
