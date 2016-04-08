#include "morozovns.h"

/**
 * Метод Гаусса
 */
void morozovns::lab1()
{
	double h;
	for (int k=0; k<N-1; k++)
        for (int i=k+1; i<N; i++){
            h=A[i][k]/A[k][k];
            b[i]=b[i]-h*b[k];
            for (int j=k; j<N; j++)
            {
                A[i][j]=A[i][j]-h*A[k][j];
            }
    }
    for (int i=N-1; i>=0; i--)
    {
        x[i]=b[i];
        for (int j=i+1; j<N; j++)
        {
            x[i]=x[i]-A[i][j]*x[j];
        }
        x[i]/=A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void morozovns::lab2()
{
    double h;
	for (int k=0; k<N-1; k++)
        for (int i=k+1; i<N; i++){
            double maaa=A[k][k]; int pm=k; double r;
            for (int j=k+1; j<N; j++)
            {
                if (fabs(A[j][k])>fabs(maaa)) {
                    pm=j;
                    maaa=A[j][k];
                }
            }
            for (int j=k; j<N; j++){r=A[pm][j]; A[pm][j]=A[k][j]; A[k][j]=r;}
            r= b[pm]; b[pm]=b[k]; b[k]=r;
            h=A[i][k]/A[k][k];
            b[i]=b[i]-h*b[k];
            for (int j=k; j<N; j++)
            {
                A[i][j]=A[i][j]-h*A[k][j];
            }
    }
    for (int i=N-1; i>=0; i--)
    {
        x[i]=b[i];
        for (int j=i+1; j<N; j++)
        {
            x[i]=x[i]-A[i][j]*x[j];
        }
        x[i]/=A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void morozovns::lab3()
{

}



/**
 * Метод прогонки
 */
void morozovns::lab4()
{

}



/**
 * Метод Якоби
 */
void morozovns::lab5()
{

}



/**
 * Метод Зейделя
 */
void morozovns::lab6()
{

}



/**
 * Один из градиентных методов
 */
void morozovns::lab7()
{

}
