#include "PolkinAV.h"

/**
 * Метод Гаусса
 */
void PolkinAV::lab1()
{
 double z;

    for(int k=0;k<N;k++)
       for(int i=k+1;i<N;i++){

          b[i]=b[i]-b[k]*A[i][k]/A[k][k];
          for(int j=N-1; j>=0;j--)
             A[i][j]=A[i][j]-A[k][j]*A[i][k]/A[k][k];
             }




    for(int i=N-1;i>=0;i--)
        {
          z=0;

          for(int j=i+1;j<N;j++)
              z=z+A[i][j]*x[j];

          x[i]=(1.0/A[i][i])*(b[i]-z);
        }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void PolkinAV::lab2()
{
double z,maximum,l,l1;int s;

     maximum=abs(A[0][0]);s=0;
        for(int i=1; i<N;i++)
            if (abs(A[i][0])>maximum)
                { maximum=abs(A[i][0]); s=i;};

        if (s!=0)
        {
            for (int j=0;j<N;j++)
            {
                l=A[0][j];
                A[0][j]=A[s][j];
                A[s][j]=l;
                l1=b[0];
                b[0]=b[s];
                b[s]=l1;
            }}

    for(int k=0;k<N;k++)
    {

       for(int i=k+1;i<N;i++){

          b[i]=b[i]-b[k]*A[i][k]/A[k][k];
          for(int j=N-1; j>=0;j--)
          {
             A[i][j]=A[i][j]-A[k][j]*A[i][k]/A[k][k];
          }
         }}




    for(int i=N-1;i>=0;i--)
        {
          z=0;

          for(int j=i+1;j<N;j++)
              z=z+A[i][j]*x[j];

          x[i]=(1.0/A[i][i])*(b[i]-z);
        }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void PolkinAV::lab3()
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
void PolkinAV::lab4()
{
double* a = new double[N];
	double* B = new double[N];

	a[0] = -A[0][1] / A[0][0];
	B[0] = b[0] / A[0][0];

	for (int i = 1; i < N; i++)
	{
		a[i] = -A[i][i + 1] / (A[i][i - 1] * a[i - 1] + A[i][i]);
		B[i] = (b[i] - A[i][i - 1] * B[i - 1]) / (A[i][i - 1] * a[i - 1] + A[i][i]);
	}

	x[N - 1] = B[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		x[i] = a[i] * x[i + 1] + B[i];
	}

	delete[] a;
	delete[] B;

}



/**
 * Метод Якоби
 */
void PolkinAV::lab5()
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
void PolkinAV::lab6()
{
double eps = 0.001;
     double* t = new double[N];
    double norm = 0;
  
 
     for (int i = 0; i < N; i++)
 			x[i] = 0;
 	do
 	{
 		for (int i = 0; i < N; i++)
 			t[i] = x[i];
  
 		for (int i = 0; i < N; i++)
 		{
 			double v = 0;
 			for (int j = 0; j < i; j++)
 				v += (A[i][j] * x[j]);
 
 			for (int j = i + 1; j < N; j++)
 				v += (A[i][j] * x[j]);
 			x[i] = (b[i] - v) / A[i][i];
 
 			norm=0;
 			for (int i = 0; i < N; i++)
 				norm += (x[i] - t[i])*(x[i] - t[i]);
 		}
 	} while (sqrt(norm) >= eps);
 
 	delete[] t;
}



/**
 * Один из градиентных методов
 */
void PolkinAV::lab7()
{

}
