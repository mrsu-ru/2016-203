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
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void karchiganovaf::lab2()
{

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void karchiganovaf::lab3()
{

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
