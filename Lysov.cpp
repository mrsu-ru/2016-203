#include "Lysov.h"

/**
 * Метод Гаусса
 */
void Lysov::lab1()
{
for (k=0;k<n;k++)
    {
        for(i=k+1;i<n;i++)
        {
            y=a[i][k]/a[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<n;j++)
            {
                a[i][j]-=a[k][j]*y;
            }
        }
    }

        for(i=n-1;i>=0;i--)
        {

            x[i]=b[i]/a[i][i];
            for(j=i+1;j<n;j++)
            {
                x[i]+=-a[i][j]*x[j]/a[i][i];
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
