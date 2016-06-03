#include "Sidorov.h"
#include <iostream>


/*Метод Гаусса*/

void Sidorov::lab1()
{
	double coefficient = 0;
	for (int line = 1; line < N; line++)
  {
    for (int i = line; i < N; i++)
    {
      coefficient = A[i][line-1] / A[line-1][line-1];
      for (int j = line; j < N; j++)
        A[i][j] -= coefficient * A[line-1][j];

      b[i] = b[i] - coefficient * b[line-1];
    }
  }

  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < N; j++)
      b[i] = b[i] - A[i][j] * x[j];

    x[i] = b[i] / A[i][i];
  }

  return;
}





void Sidorov::lab2()
{
	double coefficient;
	int max;

    for (int k=0; k<N-1; k++)
    {
      max = k;
      for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[max][k])) max = i;
        std::swap(A[max], A[k]);
        std::swap(b[max], b[k]);

        for (int i=k+1; i<N; i++)
        {

          coefficient = A[i][k]/A[k][k];
          for (int j=k; j<N; j++)
            A[i][j] = A[i][j] - coefficient*A[k][j];
          b[i] = b[i] - coefficient*b[k];
        }
    }


    for(int i = 0; i<N; i++)
    {
      x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--)
    {
      for (int j=i+1;j<N;j++)
        x[i] = x[i] - A[i][j]*x[j];
      x[i] = x[i] / A[i][i];
    }
}

void Sidorov::lab3() {
 double **L = new double*[N];
	for (int i = 0; i<N; i++)
		L[i] = new double[N];

	double *y = new double[N];


	for (int i = 0; i < N; i++)
	{
		x[i] = 0;
		y[i] = 0;
		for (int j = 0; j < N; j++)
		{
			L[i][j] = 0;
		}
	}

	double t = 0;
	for (int i = 0; i<N; i++)
	{
		for (int k = 0; k <= i - 1; k++)
			t += L[i][k] * L[i][k];

		L[i][i] = sqrt(A[i][i] - t);
		t = 0;
		for (int j = i + 1; j<N; j++)
			{
				for (int k = 0; k <= i - 1; k++)
					t += L[i][k] * L[j][k];

				L[j][i] = (A[i][j] - t) / L[i][i];
				t = 0;
			}
	}


	for (int i = 0; i<N; i++)
	{
		t = 0;
		for (int j = 0; j<i; j++)
			t += L[i][j] * y[j];

		y[i] = (b[i] - t) / L[i][i];
	}


	for (int i = N - 1; i >= 0; i--)
	{
		t = 0;
		for (int j = i + 1; j<N; j++)
			t += L[j][i] * x[j];

		x[i] = (y[i] - t) / L[i][i];
	}

}

void Sidorov::lab4() {
	double* k=new double[N];
 	double* k1=new double[N];

  k[0]=-A[0][1]/A[0][0];
  k1[0]=b[0]/A[0][0];

  for(int i=1;i<N;i++)
  {
  	k[i]=-A[i][i+1]/(A[i][i-1]*k[i-1]+A[i][i]);
   	k1[i]=(b[i]-A[i][i-1]*k1[i-1])/(A[i][i-1]*k[i-1]+A[i][i]);
  }
  x[N-1] = k1[N-1];
  for(int i=N-1; i>=0; i--)
	{
  	x[i] = k[i]*x[i+1]+k1[i];
  }
}

void Sidorov::lab5() {

}

void Sidorov::lab6() {

}

void Sidorov::lab7() {

}
