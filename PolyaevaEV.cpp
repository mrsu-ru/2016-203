#include "PolyaevaEV.h"

/**
 * Метод Гаусса
 */
void PolyaevaEV::lab1()
{
  for (int k = 0; k < N; k++)
      for (int i = k; i < N; i++)
      {
          double temp = A[i][k];
          if (temp == 0) continue;
          for (int j = 0; j < N; j++) A[i][j] = A[i][j] / temp;
          b[i] = b[i] / temp;
          if (i == k)  continue;
          for (int j = 0; j < N; j++) A[i][j] = A[i][j] - A[k][j];
          b[i] = b[i] - b[k];
      }

  for (int k = N-1; k >= 0; k--)
  {
      x[k] = b[k];
      for (int i = 0; i < k; i++) b[i] = b[i] - A[i][k] * x[k];
  }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void PolyaevaEV::lab2()
{
  for (int k = 0; k < N; k++)
  	{
  		double max = abs(A[k][k]);
          int m_ind = k;
          for (int i = k+1; i < N; i++)
  		{
  			if (abs(A[i][k]) > max)
  			{
  				max = abs(A[i][k]);
  				m_ind = i;
  			}
  		}
  		for (int j = 0; j < N; j++) std::swap(A[k][j], A[m_ind][j]);
  		std::swap(b[k], b[m_ind]);

  		for (int i = k; i < N; i++)
  		{
  			double temp = A[i][k];
  			if (temp == 0) continue;
  			for (int j = 0; j < N; j++) A[i][j] = A[i][j] / temp;
  			b[i] = b[i] / temp;
  			if (i == k)  continue;
  			for (int j = 0; j < N; j++) A[i][j] = A[i][j] - A[k][j];
  			b[i] = b[i] - b[k];
  		}
  	}

  	for (int k = N-1; k >= 0; k--)
  	{
  		x[k] = b[k];
  		for (int i = 0; i < k; i++) b[i] = b[i] - A[i][k] * x[k];
  	}

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void PolyaevaEV::lab3()
{

}



/**
 * Метод прогонки
 */
void PolyaevaEV::lab4()
{

}



/**
 * Метод Якоби
 */
void PolyaevaEV::lab5()
{

}



/**
 * Метод Зейделя
 */
void PolyaevaEV::lab6()
{

}



/**
 * Один из градиентных методов
 */
void PolyaevaEV::lab7()
{

}
