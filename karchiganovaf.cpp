#include "karchiganovaf.h"

std::string karchiganovaf::get_name()
{
  return std::string("Карчиганов Алексей Федорович");
}

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
			koef=A[i][k-1]/A[k-1][k-1];
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
		std::swap(A[_max_], A[k]);
		std::swap(b[_max_], b[k]);
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
	double L_i_k=0;
	for (int i=0; i<N; i++)
	{
		L[i]=new double[i+1];
		L_i_k=0;
		for (int j=0; j<i; j++)
		{
			L_i_k=0;
			for (int k=0; k<j; k++) L_i_k+=L[i][k]*L[j][k];
			L[i][j]=(A[i][j]-L_i_k)/L[j][j];
		}
		L_i_k=A[i][i];
		for (int k=0; k<i; k++) L_i_k-=L[i][k]*L[i][k];
		L[i][i]=sqrt(L_i_k);
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
	for (int i=0; i<N; i++) delete[] L[i];
	delete[] L;
	return;
}



/**
 * Метод прогонки
 */
void karchiganovaf::lab4()
{
	double* alph=new double[N];
	double* beta=new double[N];
	alph[0]=-A[0][1]/A[0][0];
	beta[0]=b[0]/A[0][0];
	for (int i=1; i<N; i++)
	{
		alph[i]=-A[i][i+1]/(A[i][i]+A[i][i-1]*alph[i-1]);
		beta[i]=(b[i]-A[i][i-1]*beta[i-1])/(A[i][i]+A[i][i-1]*alph[i-1]);
	}
	x[N-1]=beta[N-1];
	for (int i=N-2; i>=0; i--)
	{
		x[i]=alph[i]*x[i+1]+beta[i];
	}
	delete[] alph;
	delete[] beta;
	return;
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
