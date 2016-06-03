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
	for (int i=0; i<N-1; i++)
        for (int j=i+1; j<N; j++)
        {
            float coef=A[j][i]/A[i][i];
             b[j]-=coef*b[i];
            for (int k=0; k<N; k++)

                A[j][k]-=coef*A[i][k];
        }
        for(int i=N-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(int j=i+1;j<N;j++)
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
 for (int i=0; i<N-1; i++)
        for (int j=i+1; j<N; j++)
        {
            double aa = A[i][i];
            int st =i;
            for (int k=i+1; k<N; k++)
            {
                if (abs(A[k][i])>abs(aa));
                {
                    st =k;
                    aa=A[k][i];
                }
            }
            for (int k=i; k<N; k++){
        std::swap(A[st][k],A[i][k]);
            }
            std::swap(b[st],b[i]);
            float coef=A[j][i]/A[i][i];
             b[j]-=coef*b[i];
            for (int k=0; k<N; k++)

                A[j][k]-=coef*A[i][k];
        }
        for(int i=N-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(int j=i+1;j<N;j++)
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
        double** L=new double*[N];
	double qq=0;
	for (int i=0; i<N; i++)
	{
		L[i]=new double[i+1];
		qq=0;
		for (int j=0; j<i; j++)
		{
			qq=0;
			for (int k=0; k<j; k++)
			qq+=L[i][k]*L[j][k];
			L[i][j]=(A[i][j]-qq)/L[j][j];
		}
		qq=A[i][i];
		for (int k=0; k<i; k++)
		 qq-=L[i][k]*L[i][k];
		L[i][i]=sqrt(qq);
	}

	double* y=new double[N];

	for (int i=0; i<N; i++)
	{
		for (int j=i-1; j>=0; j--)
		b[i]-=L[i][j]*y[j];
		y[i]=b[i]/L[i][i];
	}

	for (int i=N-1; i>=0; i--)
	{
		for (int j=i+1; j<N; j++)
		y[i]-=L[j][i]*x[j];
		x[i]=y[i]/L[i][i];
	}
	delete[] y;
	for (int i=0; i<N; i++) delete[] L[i];
	delete[] L;
	return;
}



/**
 * Метод прогонки
 */
void sadovnikovev::lab4()
{
 double* P=new double[N];
 double* Q=new double[N];
    Q[0]=-A[0][1]/A[0][0];
    P[0]=b[0]/A[0][0];
   for(int i=1;i<N;i++)
    {
     P[i]=-A[i][i+1]/(A[i][i-1]*P[i-1]+A[i][i]);
     Q[i]=(b[i]-A[i][i-1]*Q[i-1])/(A[i][i-1]*P[i-1]+A[i][i]);
    }
    x[N-1] = P[N-1];
    for(int i=N-1; i>=0; i--){
     x[i] = Q[i]*x[i+1]+P[i];
    };
      delete[] P;
      delete[] Q;
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
