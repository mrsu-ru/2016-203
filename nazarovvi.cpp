#include "nazarovvi.h"
#include "cmath"
/**
 * Метод Гаусса
 */
void nazarovvi::lab1()
{
    double coef = 0;
    for (int k=0; k<N-1; k++)
    {
        for (int i=k+1; i<N; i++)
        {
            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
            {
                A[i][j] -= coef*A[k][j];
               // if (abs(A[i][j])<1e-16) A[i][j] = 0;
            }
            b[i] -= coef*b[k];
        }
    }
    for(int i = 0; i<N; i++)
        x[i]=b[i];

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void nazarovvi::lab2()
{
    long double coef;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i;
        swap(A[maxn], A[k]);
        swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {

            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= coef*A[k][j];
            b[i] -= coef*b[k];
        }
    }


    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void nazarovvi::lab3()
{
	long double** L = new long double*[N];
    for (int i=0; i<N; i++)
        L[i] = new long double[N];
	long double* y = new long double[N];
	long double s=0;
	//зануляем матрицу Л
	for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            {
                L[i][j]=0;
            }
	//находим нижнетреугольную матрицу Л
	for (int k = 0; k < N; k++)
    {
        for(int i=0; i<k; i++)
            s+=L[k][i]*L[k][i];

        L[k][k]=sqrt(A[k][k]-s);
        s = 0;

        for(int i=k+1; i < N; i++)
        {
            for (int j=0; j<i-1; j++)
                s+=L[i][j]*L[k][j];

            L[i][k] = (A[i][k]-s)/L[k][k];
            s = 0;
        };
    }


	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

	//решаем первую систему
    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int k=0; k < i; k++)
			s += L[i][k]*y[k];

        y[i] = (b[i] - s)/L[i][i];
        s = 0;
    }
    //решаем вторую систему
	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int k=i+1;k<N;k++)
			s += L[k][i]*x[k];

        x[i] = (y[i] - s)/L[i][i];
        s = 0;
    }
    delete[] y;
}



/**
 * Метод прогонки
 */
void nazarovvi::lab4()
{
	long double* P = new long double[N];
    long double* Q = new long double[N];
    for (int i=0; i<N; i++)
    {
        P[i]=0;
        Q[i]=0;
    }

    P[0] = -A[0][1]/A[0][0];
    Q[0] = b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        P[i] = A[i][i+1]/(-A[i][i-1]*P[i-1]-A[i][i]);
        Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i-1]*P[i-1]-A[i][i]);
    }
    x[N-1] = Q[N-1];
    for(int i=N-2; i>=0; i--)
        x[i] = P[i]*x[i+1]+Q[i];
    delete[] P;
    delete[] Q;
}



/**
 * Метод Якоби
 */
void nazarovvi::lab5()
{
    long double eps = 0.0001;
    long double* y = new double[N];
	long double norm;
    do {
		for (int i = 0; i < N; i++)
        {
			y[i] = b[i];
			for (int j = 0; j < N; j++)
			{
				if (i != j)
					y[i] -= A[i][j] * x[j];
			}
			y[i] /= A[i][i];
		}
        norm = abs(x[0] - y[0]);
		for (int h = 0; h < N; h++)
        {
			if (abs(x[h] - y[h]) > norm)
				norm = abs(x[h] - y[h]);
			X[h] = y[h];
		}
	} while (norm > eps);
	delete[] y;

}



/**
 * Метод Зейделя
 */
void nazarovvi::lab6()
{
    long double eps = 0.0001;
    long double* y = new long double[N];
    long double norm = 0;
	long double var = 0;

    for (int i = 0; i < N; i++)
			x[i] = 0;
	do
	{
		for (int i = 0; i < N; i++)
			y[i] = x[i];

		for (int i = 0; i < N; i++)
		{
			var = 0;
            norm = 0;
			for (int j = 0; j < i; j++)
				var += (A[i][j] * x[j]);
			for (int j = i + 1; j < N; j++)
				var += (A[i][j] * x[j]);
			x[i] = (b[i] - var) / A[i][i];
			for (int i = 0; i < N; i++)
				norm += (x[i] - y[i])*(x[i] - y[i]);
		}
	} while (sqrt(norm) >= eps);

	delete[] y;
}



void multiplication(long double** M, long double* v, long double* r)
{
    double s=0;
    for (int i=0; i < N; i++)
    {
        for (int j=0; j < N; j++)
                s += M[i][j]*v[j];
        r[i] = s;
        s = 0;
    }
};
void multiplication(long double a, long double* v, long double* r)
{
    for (int i=0; i < N; i++)
        r[i] = a*v[i];
};

long double scale(long double* v1, long double* v2)
{
    long double result = 0;
    for (int i=0; i < N; i++)
        result += v1[i]*v2[i];
    return result;
}


void subtr(long double* v1, long double* v2, long double* r)
{
    for (int i=0; i < N; i++)
        r[i] = v1[i]-v2[i];
}

/**
 * Один из градиентных методов
 */
void nazarovvi::lab7()
{
	double eps = 0.00000001;
    double* y = new double[N];
    double* r = new double[N];
    double* buff = new double[N];
    double t=0;
    double norm=0;

    for (int i=0; i<N; i++)
    {
        y[i] = 0;
        r[i] = 0;
        buff[i] = 0;
    }

    do
    {
		multiplication(A, y, buff);
        subtr(buff, b, r);
        multiplication(A, r, buff);
        t=scale(r, r)/scale(buff, r);
        multiplication(t, r, buff);
        subtr(x, buff, y);
        norm = abs(x[0]-y[0]);
        for (int i = 0; i < N; i++)
        {
			if (abs(x[i] - y[i]) > norm)
				norm = abs(x[i] - y[i]);
            x[i] = y[i];
		}
    }while(norm >= eps);
    delete[] r;
    delete[] y;
    delete[] buff;
};

double** multiplication(double **a, double **b)
 {
    double **c = new double* [N];
    double s;
    for (int i=0; i<N; i++)
        c[i] = new double [N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
             s = 0;
             for(int k=0; k<N; k++) {
                 s += a[i][k]*b[k][j];
             }
             c[i][j] = s;
        }
     }
   return c;
}
/**
 * Решение полной проблемы собственных значений(Метод вращения)
 */
void nazarovvi::lab8()
{
	double eps = 0.00000001;

	double** U = new double*[N];
    for (int i=0; i<N; i++)
        U[i] = new double[N];
    double** Ut = new double*[N];
    for (int i=0; i<N; i++)
        Ut[i] = new double[N];
	double** L = new double*[N];
    for (int i=0; i<N; i++)
        L[i] = new double[N];
	double phi = 0, t = 0;
    int maxi, maxj;
	for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            L[i][j] = A[i][j];
	do {
		phi = 0;
		t = 0;
		maxi = 0; maxj = 1;
		//looking for max elem
		for(int i=0; i < N; i++)
			for(int j=0; j < i; j++)
				if((i!=j)&&(abs(L[i][j]) >= abs(L[maxi][maxj])))
					{
						maxi = i;
						maxj = j;
					}
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				if(i == j) {
					U[i][j] = 1;
					Ut[i][j] = 1;
				}
				else {
					U[i][j] = 0;
					Ut[i][j] = 0;
				}
		//calculating angle
		phi = atan(2*L[maxi][maxj]/(L[maxi][maxi]-L[maxj][maxj]))/2;

		U[maxi][maxj] = - sin(phi);
		U[maxj][maxi] = sin(phi);
		U[maxi][maxi] = cos(phi);
		U[maxj][maxj] = cos(phi);

		Ut[maxi][maxj] = sin(phi);
		Ut[maxj][maxi] = -sin(phi);
		Ut[maxi][maxi] = cos(phi);
		Ut[maxj][maxj] = cos(phi);

		L = multiplication(multiplication(Ut,L),U);
		for(int i=0; i < N; i++)
			for(int j=0; j < i; j++)
				t += L[i][j]*L[i][j];
	}while(sqrt(t) >= eps);
	for(int i=0; i < N; i++)
        x[i] = L[i][i];
	for(int i=0; i < N; i++)
	{
		delete[] L[i];
		delete[] U[i];
		delete[] Ut[i];
	}
	delete[] L;
	delete[] U;
	delete[] Ut;

};




