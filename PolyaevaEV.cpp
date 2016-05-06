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
  double temp, temp2;
  for (int i = 0; i < N; i++)
  {
      temp = 0.0; temp2 = 1;
      for (int k = 0; k < i; k++) temp += pow(A[k][i], 2);
      A[i][i] = sqrt(A[i][i] - (double)temp);

      if(i==0) temp2 = 0;
      else for(int l=i; l<N; l++) temp2 = temp2 * A[i-1][l];

      for (int j = 0; j < N; j++)
      {
          if (j < i) A[i][j] = 0;
          else if (i == j)  continue;
          else A[i][j] = (A[i][j] - temp2) / A[i][i];
      }
  }

  for (int i = 0; i < N; i++)
  {
      temp = 0;
      for (int k = 0; k < i; k++) temp = temp + A[k][i] * b[k];
      b[i] = (b[i] - temp) / A[i][i];
  }

  for (int k = N-1; k >= 0; k--)
  {
      double res = 0;
      for (int i = k+1; i < N; i++) res += A[k][i] * x[i];
      x[k] = (b[k] - res)/A[k][k];
  }
}

/**
 * Метод прогонки
 */
void PolyaevaEV::lab4()
{
    double* AA = new double[N];
    double* B = new double[N];

	  AA[0] = A[0][1]/(-A[0][0]);
    B[0] = b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        AA[i] = A[i][i+1]/(-A[i][i-1]*AA[i-1]-A[i][i]);
        B[i] = (-b[i] + A[i][i-1]*B[i-1])/(-A[i][i-1]*AA[i-1]-A[i][i]);
    }

    for(int i=N-1; i>=0; i--) x[i] = AA[i]*x[i+1]+B[i];

    delete[] AA;
    delete[] B;
}



/**
 * Метод Якоби
 */
void PolyaevaEV::lab5()
{
  double eps = 0.001;
	double* Y = new double[N];
	double norm;

	do {
		for (int i = 0; i < N; i++)
		{
			Y[i] = b[i];
			for (int k = 0; k < N; k++)
			{
				if (i != k) Y[i] -= A[i][k] * x[k];
			}
			Y[i] = Y[i]/A[i][i];
		}

        norm = fabs(x[0] - Y[0]);

		for (int i = 0; i < N; i++)
		{
			if (fabs(x[i] - Y[i]) > norm) norm = fabs(x[i] - Y[i]);
			x[i] = Y[i];
		}
	} while (norm > eps);

	delete[] Y;
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
