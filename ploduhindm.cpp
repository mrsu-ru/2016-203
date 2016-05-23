#include "ploduhindm.h"

/**
 * Метод Гаусса
 */
void ploduhindm::lab1()
{
    for (int i = 0; i < N; i++)
        x[i] = b[i];
     long double m;
     for (int k = 0; k < N-1; k++)
        {
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void ploduhindm::lab2()
{
    for (int i = 0; i < N; i++)
        x[i] = b[i];
     long double m;
     int index;
     for (int k = 0; k < N-1; k++)
        {
            index = k;
            for (int i=k+1; i<N; i++)
                if(abs(A[i][k]) > abs(A[index][k])) index = i;
            std::swap(A[index], A[k]);
            std::swap(b[index], b[k]);
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ploduhindm::lab3()
{
    long double** L = new long double*[N];
    for (int i=0; i<N; i++)
        L[i] = new long double[N];
	long double* y = new long double[N];
	long double s=0;
	for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        {
                L[i][j]=0;
        }
	for (int i = 0; i < N; i++)
        {
            for(int k=0; k<i; k++)
                s+=L[i][k]*L[i][k];

            L[i][i]=sqrt(A[i][i]-s);
            s = 0;

        for (int j = i+1; j < N; j++)
            {
                for (int k=0; k<j-1; k++)
                    s+=L[j][k]*L[i][k];
                L[j][i] = (A[j][i]-s)/L[i][i];
                s = 0;
            };
        }

	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int j=0; j < i; j++)
			s += L[i][j]*y[j];

        y[i] = (b[i] - s)/L[i][i];
        s = 0;
    }

	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s += L[j][i]*x[j];

        x[i] = (y[i] - s)/L[i][i];
        s = 0;
    }
    delete[] y;
    for(int i=0; i<N; i++)
        delete[] L[i];
    delete[] L;
}



/**
 * Метод прогонки
 */
void ploduhindm::lab4()
{
    long double* P = new long double[N];
    long double* Q = new long double[N];
    for (int i=0; i<N; i++)
    {
        P[i]=0;
        Q[i]=0;
    }

    P[0]=A[0][1]/(-A[0][0]);
    Q[0]=b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        P[i] = A[i][i+1]/(-A[i][i]-A[i][i-1]*P[i-1]);
        Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i]-A[i][i-1]*P[i-1]);
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
void ploduhindm::lab5()
{
    long double eps = 0.0001;
    long double* p = new long double[N];
	long double norm;
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
        norm = fabs(x[0] - p[0]);
		for (int h = 0; h < N; h++)
        {
			if (fabs(x[h] - p[h]) > norm)
				norm = fabs(x[h] - p[h]);
			x[h] = p[h];
		}
	} while (norm > eps);
	delete[] p;
}



/**
 * Метод Зейделя
 */
void ploduhindm::lab6()
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
 double ploduhindm::mskl(double *a, double *b)
{
    double x=0;
    for (int i=0; i<N; i++)
        x+=a[i]*b[i];
    return x;
}
double* ploduhindm::mvect(double **a, double *b)
{
     double *x = new double [N];
     double m=0;
     for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
                m+=a[i][j]*b[j];
            x[i]=m;
            m=0;
        }
    return x;
}
double* ploduhindm::subsvect(double *a, double *b)
{
     double *x = new double [N];
     for (int i=0; i<N; i++)
        x[i]=a[i]-b[i];
    return x;
}
double* ploduhindm::numvect(double *a, double m)
{
     double *x = new double [N];
     for (int i=0; i<N; i++)
        x[i]=a[i]*m;
    return x;
}
void ploduhindm::lab7()
{
    double eps = 0.0001;
    double* p = new double[N];
    double* r = new double[N];
	double norm,t;
	for (int i=0; i<N; i++)
    {
        x[i]=0;
        p[i]=0;
    }
    do {
        r=subsvect(mvect(A,x),b);
        t=mskl(r,r)/mskl(mvect(A,r),r);
        p=subsvect(p,numvect(r,t));
        norm = fabs(x[0] - p[0]);
		for (int h = 0; h < N; h++)
        {
			if (fabs(x[h] - p[h]) > norm)
				norm = fabs(x[h] - p[h]);
			x[h] = p[h];
		}
    } while (norm>eps);
}

double** ploduhindm::multMatr(double **a, double **b)
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
double** ploduhindm::transMatr(double **a)
{
    double **c = new double* [N];
    for (int i=0; i<N; i++)
         c[i] = new double [N];
    for (int i=0; i<N; i++)
       for (int j=0; j<N; j++)
        c[i][j]=a[j][i];
    return c;
}
void ploduhindm::lab8()
{
    double eps=0.001;
    double amax,f=0,s;
    int imax=0,jmax=0;
    double **U = new double* [N];
        for (int i=0; i<N; i++)
         U[i] = new double [N];
     do
     {
        amax=0;
        s=0;
        for(int i=0;i<N;i++)
          for(int j=0;j<N;j++)
            if ((abs(A[i][j])>amax)&&(i!=j))
            {
                amax=abs(A[i][j]);
                imax=i;
                jmax=j;
            }
        if (A[imax][imax]==A[jmax][jmax]) f=M_PI/4; else
            f=0.5*(atan(2*amax/(A[imax][imax]-A[jmax][jmax])));
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
               U[i][i]=1;
               if (i!=j) U[i][j]=0;
            }
        U[jmax][imax]=sin(f);
        U[imax][imax]=cos(f);
        U[jmax][jmax]=cos(f);
        U[imax][jmax]=-sin(f);
        A=multMatr(multMatr(transMatr(U),A),U);
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                    s+=A[i][j]*A[i][j];
        s=sqrt(s);
    } while (s>eps);
    for(int i=0;i<N;i++)
        x[i]=A[i][i];
}
