#include "Zelyunko.h"

/**
 * Метод Гаусса
 */
void Zelyunko ::lab1(){

//Приведение к нижне треугольному виду матрицы A расширенной присоединением В
for(int i=0;i<N;i++)
{
    for(int k=i+1;k<N;k++)
    {
        b[k]=double(double(-A[i][i]/A[k][i])*b[k]+b[i]);

        for(int l=N-1;l>=i;l--)
        {
            A[k][l]=double(double(-A[i][i]/A[k][i])*A[k][l]+A[i][l]);
        }
    }
}


//Вычисление корней
double z=0; //z- используется для нахожения i-ого неизвестного за счет уже найденных N-i неизвестных

 for(int i=N-1;i>=0;i--)
{
    z=0;

    for(int g=N-1;g>i;g--)
    {
     z+=A[i][g]*x[g];
    }

  x[i]=double((b[i]-z)/A[i][i]);
}
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Zelyunko ::lab2()
{

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Zelyunko ::lab3()
{

}



/**
 * Метод прогонки
 */
void Zelyunko::lab4()
{

}



/**
 * Метод Якоби
 */
void Zelyunko::lab5()
{

}



/**
 * Метод Зейделя
 */
void Zelyunko::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Zelyunko::lab7()
{

}
