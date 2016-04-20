#include "karchiganovaf.h"

/**
 * Метод Гаусса
 */
void karchiganovaf::lab1()
{

	double koef=0;
	for (int k=1; k<N; k++)
	{
		for (int i=k; i<N; i++)
		{
			koef=A[i][k-1]/a[k-1][k-1];
			for (int j=k; j<N; j++) A[i][j]-=koef*A[k-1][j];
			b[i]-=koef*b[k-1];
		}
	}
	for (int i=N-1; i>=0; i--)
	{
		for (int j=i+1; j<N; j++) b[i]-=A[i][j]*x[j];
		x[i]=b[i]/A[i][i];
	}
	return;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void karchiganovaf::lab2()
{
	double A_max_k=0;
	int _max_=0;
	for (int k=0; k<(N-1); k++)
	{
		_max_=k;
		A_max_k=abs(A[_max_][k]);
		for (int i=k+1; i<N; i++) if (A_max_k<abs(A[i][k]))
		{
			_max_=i;
			A_max_k=abs(A[_max_][k]);
		}
		swap(A[_max_], A[k]);
		swap(b[_max_], b[k]);
	}
	lab1();
	return;
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void karchiganovaf::lab3()
{
	double** L=new double*[N];
	double L_i_p=0;
	for (int i=0; i<N; i++)
	{
		L[i]=new double[N];
		for (int j=0; j<i; j++)
		{
			L_i_p=0;
			for (int p=0; p<j; p++) L_i_p+=L[i][p]*L[j][p];
			L[i][j]=sqrt(A[i][j]-L_i_p)/L[j][j];
		}
		L_i_p=A[i][i];
		for (int p=0; p<i; p++) L_i_p-=L[i][p]*L[i][p];
		L[i][i]=sqrt(L_i_p);
	}

	double* y=new double[N];

	for (int i=0; i<N; i++)
	{
		for (int j=i-1; j>=0; j--) b[i]-=L[i][j]*y[j];
		y[i]=b[i]/L[i][i];
	}

	for (int i=N-1; i>=0; i--)
	{
		for (int j=i+1; j<N; j++) y[i]-=L[j][i]*x[j];
		x[i]=y[i]/L[i][i];
	}
	delete[] y;
	return;
}



/**
 * Метод прогонки
 */
void karchiganovaf::lab4()
{

}



/**
 * Метод Якоби
 */
void karchiganovaf::lab5()
{

}



/**
 * Метод Зейделя
 */
void karchiganovaf::lab6()
{

}



/**
 * Один из градиентных методов
 */
void karchiganovaf::lab7()
{

}
