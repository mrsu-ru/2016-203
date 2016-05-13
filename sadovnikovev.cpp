#include "sadovnikovev.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>
/**
 * Метод Гаусса
 */
void sadovnikovev::lab1()
{
	for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
        {
            float coef=A[j][i]/A[i][i];
             b[j]-=coef*b[i];
            for (int k=0; k<n; k++)

                A[j][k]-=coef*A[i][k];
        }
        for(i=n-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(j=i+1;j<n;j++)
            {
                x[i]-=A[i][j]*x[j]/A[i][i];
            }
        }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void sadovnikovev::lab2()
{
 for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
        {
            double aa = A[i][i];
            int st =i;
            for (int k=i+1; k<n; k++)
            {
                if (abs(A[k][i])>abs(aa));
                {
                    st =k;
                    aa=A[k][i];
                }
            }
            for (int k=i; k<n; k++){
        swap(A[st][k],A[i][k]);
            }
            swap(b[st],b[i]);
            float coef=A[j][i]/A[i][i];
             b[j]-=coef*b[i];
            for (int k=0; k<n; k++)

                A[j][k]-=coef*A[i][k];
        }
        for(i=n-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(j=i+1;j<n;j++)
            {
                x[i]-=A[i][j]*x[j]/A[i][i];
            }
        }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void sadovnikovev::lab3()
{

}



/**
 * Метод прогонки
 */
void sadovnikovev::lab4()
{

}



/**
 * Метод Якоби
 */
void sadovnikovev::lab5()
{

}



/**
 * Метод Зейделя
 */
void sadovnikovev::lab6()
{

}



/**
 * Один из градиентных методов
 */
void sadovnikovev::lab7()
{

}