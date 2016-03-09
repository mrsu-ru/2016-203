#include "ploduhindm.h"

/**
 * Метод Гаусса
 */
void ploduhindm::lab1()
{
    for (int i = 0; i < n; i++)
        x[i] = b[i];
     long double m;
     for (int k = 0; k < n; k++)
        {
             for (int i = k+1; i < n; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < n; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=n-1;i>=0;i--)
    {
        for (int j=i+1;j<n;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void ploduhindm::lab2()
{

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
