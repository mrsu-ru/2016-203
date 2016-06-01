#include "novikovdv.h"

/**
 * Метод Гаусса
 */
void novikovdv::lab1()
{
 double t=0;
    for(int k=0; k<N; k++)
        {
            for(int i=k+1; i<N; i++)
                {
                    t=A[i][k]/A[k][k];
                    b[i]-=t*b[k];

                    for (int j=0; j<N; j++)
                        A[i][j]-=t*A[k][j];
                }
        }

        for(int i=N-1; i>=0; i--)
        {
            t=0;
            for(int j=i+1; j<N; j++)
            t+=A[i][j]*x[j];
            x[i]=(b[i]-t)/A[i][i];
        }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void novikovdv::lab2()
{

    double t=0;
    for(int k=0; k<N; k++)
        {
            double max_el=abs(A[k][k]);  //Замена строк
            int max_id=k;
            for (int i=k+1; i<N; i++)
                {
                    if (abs(A[i][k]) > max_el)
                        {
                            max_el=abs(A[max_id][k]);
                            max_id=i;
                        }
                }
             for (int j=0; j<N; j++)
                std::swap(A[k][j], A[max_id][j]);
                std::swap(b[k], b[max_id]);


        for(int i=k+1; i<N; i++)
            {
                t=A[i][k]/A[k][k];
                b[i]-=t*b[k];

                for (int j=0; j<N; j++)
                    A[i][j]-=t*A[k][j];

            }
        }

        for(int i=N-1; i>=0; i--)
        {
            t=0;
            for(int j=i+1; j<N; j++)
            t+=A[i][j]*x[j];
            x[i]=(b[i]-t)/A[i][i];
        }

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void novikovdv::lab3()
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
void novikovdv::lab4()
{
    double* Alpha = new double[N];
	double* Beta = new double[N];

	Alpha[0] = -A[0][1] / A[0][0];
	Beta[0] = b[0] / A[0][0];

	for (int i = 1; i < N; i++)
	{
		Alpha[i] = -A[i][i + 1] / (A[i][i - 1] * Alpha[i - 1] + A[i][i]);
		Beta[i] = (b[i] - A[i][i - 1] * Beta[i - 1]) / (A[i][i - 1] * Alpha[i - 1] + A[i][i]);
	}

	x[N - 1] = Beta[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		x[i] = Alpha[i] * x[i + 1] + Beta[i];
	}

	delete[] Alpha;
	delete[] Beta;
}



/**
 * Метод Якоби
 */
void novikovdv::lab5()
{

}



/**
 * Метод Зейделя
 */
void novikovdv::lab6()
{

}



/**
 * Один из градиентных методов
 */
double novikovdv::sklr(double *x, double *y)
{
	double s = 0;
	for (int i = 0; i<N; i++)
		s += x[i] * y[i];
	return(s);
}
double* novikovdv::vichvect(double *x, double *y)
{
	double *t = new double[N];
	for (int i = 0; i<N; i++)
		t[i] = x[i] - y[i];
	return t;
}
double* novikovdv::matrvect(double **A, double *x)
{
	double *t = new double[N];
	for (int j = 0; j<N; j++)
		t[j] = 0;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++)
			t[i] = t[i] + A[i][j] * x[j];
	}
	return (t);
}


double* novikovdv::mult(double *A, double p)
{
	double *t = new double[N];
	for (int i = 0; i<N; i++)
		t[i] = A[i] * p;
	return (t);
}



void novikovdv::lab7()
{
    double tau, norm = 0, eps = 0.001;
	double *r = new double[N];
	for (int i = 0; i<N; i++)
	{
		x[i] = 0;
	}

	do{
		r = vichvect(b, matrvect(A, x));
		tau = -(sklr(matrvect(A, r), r) / sklr(matrvect(A, r), matrvect(A, r)));
		x=vichvect(x, mult(r, tau));

		for (int i = 0; i<N; i++)
			norm += r[i] * r[i];
		norm = fabs(norm) / N;

	} while (norm > eps);
	delete[] r;
}
