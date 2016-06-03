#include "titkovmd.h"

/**
 * Метод Гаусса
 */
void titkovmd::lab1()
{
    long double m;
    for (int i = 0; i < N; i++)
        x[i] = b[i];
    for (int k = 0; k < N-1; k++)
        {
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j] = A[i][j] - m * A[k][j];
  				}
                 x[i] = x[i]- m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i] = x[i]- A[i][j]*x[j];
        x[i]=x[i]/A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void titkovmd::lab2()
{
    long double m;
    int ind;
    for (int i = 0; i < N; i++)
        x[i] = b[i];
     for (int k = 0; k < N-1; k++)
        {
            ind = k;
            for (int i=k+1; i<N; i++)
                if(abs(A[i][k]) > abs(A[ind][k])) ind = i;
            std::swap(A[ind], A[k]);
            std::swap(b[ind], b[k]);
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]= A[i][j]- m * A[k][j];
  				}
                 x[i] = x[i]- m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i] = x[i]- A[i][j]*x[j];
        x[i]/= x[i]/ A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void titkovmd::lab3()
{
    long double** l = new long double*[N];
    long double* y = new long double[N];
	long double s=0;
    for (int i=0; i<N; i++)
        l[i] = new long double[N];
	for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        {
                l[i][j]=0;
        }
	for (int i = 0; i < N; i++)
        {
            for(int k=0; k<i; k++)
                s = s + l[i][k]*l[i][k];

            l[i][i]=sqrt(A[i][i]-s);
            s = 0;

        for (int j = i+1; j < N; j++)
            {
                for (int k=0; k<j-1; k++)
                    s+=l[j][k]*l[i][k];
                l[j][i] = (A[j][i]-s)/l[i][i];
                s = 0;
            };
        }

	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/l[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int j=0; j < i; j++)
			s = s + l[i][j]*y[j];

        y[i] = (b[i] - s)/l[i][i];
        s = 0;
    }

	x[N-1] = y[N-1]/l[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s = s + l[j][i]*x[j];

        x[i] = (y[i] - s)/l[i][i];
        s = 0;
    }
    delete[] y;
    for(int i=0; i<N; i++)
        delete[] l[i];
    delete[] l;
}



/**
 * Метод прогонки
 */
void titkovmd::lab4()
{
    long double* p = new long double[N];
    long double* q = new long double[N];
    for (int i=0; i<N; i++)
    {
        p[i]=0;
        q[i]=0;
    }

    p[0]=A[0][1]/(-A[0][0]);
    q[0]=b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        p[i] = A[i][i+1]/(-A[i][i]-A[i][i-1]*p[i-1]);
        q[i] = (-b[i] + A[i][i-1]*q[i-1])/(-A[i][i]-A[i][i-1]*p[i-1]);
    }

    x[N-1] = q[N-1];
    for(int i=N-2; i>=0; i--)
        x[i] = p[i]*x[i+1]+q[i];

    delete[] p;
    delete[] q;

}



/**
 * Метод Якоби
 */
void titkovmd::lab5()
{
    long double eps = 0.0001;
    long double* p = new long double[N];
	long double normal;
    for (int i = 0; i < N; i++)
        x[i]=0;
    do {
		for (int i = 0; i < N; i++)
        {
			p[i] = b[i];
			for (int j = 0; j < N; j++)
				if (i != j) p[i] -= A[i][j] * x[j];
			p[i] /= A[i][i];
		}
        normal = fabs(x[0] - p[0]);
		for (int h = 0; h < N; h++)
        {
			if (fabs(x[h] - p[h]) > normal)
				normal = fabs(x[h] - p[h]);
			x[h] = p[h];
		}
	} while (normal > eps);
	delete[] p;
}



/**
 * Метод Зейделя
 */
void titkovmd::lab6()
{
    long double eps = 0.0001;
    long double *p = new long double [N];
    bool conv;
    for (int i = 0; i < N; i++)
        x[i]=0;
    do
    {
        for (int i = 0; i < N; i++)
            p[i] = x[i];
        for (int i = 0; i < N; i++)
        {
            double var = 0;
            for (int j = 0; j < i; j++)
                var += (A[i][j] * x[j]);
            for (int j = i + 1; j < N; j++)
                var += (A[i][j] * p[j]);
            x[i] = (b[i] - var) / A[i][i];
        }
        conv=true;
        for (int i = 0; i < N; i++)
            if (fabs(x[i]-p[i])>=eps){
                conv=false;
                break;
            }

    } while (conv==false);
    delete[] p;

}



/**
 * Один из градиентных методов
 */
void titkovmd::lab7()
{

}
