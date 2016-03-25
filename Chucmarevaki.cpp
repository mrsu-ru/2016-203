#include "Chucmarevaki.h"

/**
 * Метод Гаусса
 */
void Chucmarevaki ::lab1()
{
    for (int k  = 0; k < N; k++)
    {
        for (int i = k + 1; i < N; i++)
        {
            double mu = A[i][k]/A[k][k];
            for(int j = 0; j < N; j++)
                 A[i][j] -= A[k][j]*mu;
            b[i] -= b[k] *mu;
        }
      }

     for (int m = N-1; m >= 0; m--)
     {
         double sum = 0;
         for(int i = N-1; i > m ; i--)
              sum  = sum + x[i]*A[m][i];
         x[m] = (b[m] - sum)/A[m][m];
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Chucmarevaki::lab2()
{

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Chucmarevaki::lab3()
{

}



/**
 * Метод прогонки
 */
void Chucmarevaki::lab4()
{

}



/**
 * Метод Якоби
 */
void Chucmarevaki::lab5()
{

}



/**
 * Метод Зейделя
 */
void Chucmarevaki::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Chucmarevaki::lab7()
{

}
