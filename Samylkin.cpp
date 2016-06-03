#include "Samylkin.h"

/**
 * Метод Гаусса
 */
void Samylkin::lab1()
{
  for(int k=0; k<N; k++)
        for(int i=k+1; i<N;i++)
        {
           float p=A[i][k]/A[k][k];
            b[i]=b[i]-(b[k]*p);
            for(int j=0;j<N;j++)
                A[i][j]=A[i][j]-A[k][j]*(A[i][k]/A[k][k]);
        }


    double s=0;
    x[N-1]=b[N-1]/A[N-1][N-1];
    for(int i=N-1;i>=0;i--)
    {

        for (int j=i+1; j<N;j++)
            s=s+A[i][j]*x[j];
        x[i]=(b[i]-s)/A[i][i];
        s=0;

    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Samylkin::lab2()
{
    int k=0,h=A[0][0];
    for (int i=0; i<N; i++)
    {

            if (h<A[i][0])
            {
                h=A[i][0];
                k=i;
            }
    }
    if (k!=0)
        for (int j=0; j<N; j++)
        {
        std::swap(A[0][j],A[k][j]);
        }
        int p=0,t=0;
        float y;
        while (p<N)
        {

            for (int i=p+1; i<N; i++)
            {
                 y=-A[i][t];
                 for (int j=t; j<N; j++)
                 {
                      A[i][j]=A[i][j]+A[p][j]/A[p][t]*(y);

                 }
                 b[i]=b[i]+b[p]/A[p][t]*(y);
            }
            p++;
            t++;
        }
        t=N-1;
double s=0;
    x[N-1]=b[N-1]/A[N-1][N-1];
    for(int i=N-1;i>=0;i--)
    {

        for (int j=i+1; j<N;j++)
            s=s+A[i][j]*x[j];
        x[i]=(b[i]-s)/A[i][i];
        s=0;

    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Samylkin::lab3()
{
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

    delete[] y;
	for (int i = 0; i<N; i++)
		delete[] L[i];
	delete[] L;

}



/**
 * Метод прогонки
 */
void Samylkin::lab4()
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
void Samylkin::lab5()
{

}



/**
 * Метод Зейделя
 */
void Samylkin::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Samylkin::lab7()
{

}
