#include "timovkin.h"

/**
 * Метод Гаусса
 */
void timovkin::lab1()
{
for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }

 for (int i = N-1; i>=0; i--)
 for (int k=i-1;k>=0;k--)
 {
     c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=N-1;j>=0;j--)
     A[k][j]=A[k][j]-A[i][j]*c;

}
    for (int j=0; j<N; j++)
    {    x[j]=b[j]/A[j][j];}
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void timovkin::lab2()
{
  for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }
 for(int i=N;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+A[i][j]*x[j];
      x[i]=(b[i]-s)/A[i][i];
    }

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ivanovii::lab3()
{

}



/**
 * Метод прогонки
 */
void ivanovii::lab4()
{

}



/**
 * Метод Якоби
 */
void ivanovii::lab5()
{

}



/**
 * Метод Зейделя
 */
void ivanovii::lab6()
{

}



/**
 * Один из градиентных методов
 */
void ivanovii::lab7()
{

}
