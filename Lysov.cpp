#include "Lysov.h"

/**
 * Метод Гаусса
 */
void Lysov::lab1()
{
  int i,j,k;
  double y;
for (k=0;k<N;k++)
    {
        for(i=k+1;i<N;i++)
        {
            y=A[i][k]/A[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<N;j++)
            {
                A[i][j]-=A[k][j]*y;
            }
        }
    }

        for(i=N-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(j=i+1;j<N;j++)
            {
                x[i]+=-A[i][j]*x[j]/A[i][i];
            }
        }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Lysov::lab2()
{

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Lysov::lab3()
{

}



/**
 * Метод прогонки
 */
void Lysov::lab4()
{

}



/**
 * Метод Якоби
 */
void Lysov::lab5()
{

}



/**
 * Метод Зейделя
 */
void Lysov::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Lysov::lab7()
{

}
