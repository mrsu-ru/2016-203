#include "Levshtanoviv.h"

/**
 * Метод Гаусса
 */
void Levshtanoviv::lab1()
{
for (int k = 0; k<n; k++)
     for (int i=k+1;i<n;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<n;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }

     for (int k = n-1; k>=0; k--)
     for (int i=k-1;i>=0;i--)
      for (int j=n-1;j>=0;j--)
 {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<n;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Levshtanoviv::lab2()
{
for (int k = 0; k<n; k++)
     for (int i=k+1;i<n;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<n;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }


      for(int i=n-1; i>=0; i--)

      {s=0;
          for(int j=i+1; j<=n; j++)
             s=s+A[i][j]*x[j];
         x[i]=(b[i]-s)/(A[i][i]);
      }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Levshtanoviv::lab3()
{

}



/**
 * Метод прогонки
 */
void Levshtanoviv::lab4()
{

}



/**
 * Метод Якоби
 */
void Levshtanoviv::lab5()
{

}



/**
 * Метод Зейделя
 */
void Levshtanoviv::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Levshtanoviv::lab7()
{

}
