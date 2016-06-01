#include "karchiganovaf.h"

#define max(a,b)  (a)>(b)?(a):(b)


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
	return;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void karchiganovaf::lab2()
{
	double A_max_k=0;
	int _max_=0;
	for (int k=0; k<(N-1); k++)
	{
		_max_=k;
		A_max_k=abs(A[_max_][k]);
		for (int i=k+1; i<N; i++) if (A_max_k<abs(A[i][k]))
		{
			_max_=i;
			A_max_k=abs(A[_max_][k]);
		}
		std::swap(A[_max_], A[k]);
		std::swap(b[_max_], b[k]);
	}
	lab1();
	return;
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void karchiganovaf::lab3()
{
	double** L=new double*[N];
	double L_i_k=0;
	for (int i=0; i<N; i++)
	{
		L[i]=new double[i+1];
		L_i_k=0;
		for (int j=0; j<i; j++)
		{
			L_i_k=0;
			for (int k=0; k<j; k++) L_i_k+=L[i][k]*L[j][k];
			L[i][j]=(A[i][j]-L_i_k)/L[j][j];
		}
		L_i_k=A[i][i];
		for (int k=0; k<i; k++) L_i_k-=L[i][k]*L[i][k];
		L[i][i]=sqrt(L_i_k);
	}

	double* y=new double[N];

	for (int i=0; i<N; i++)
	{
		for (int j=i-1; j>=0; j--) b[i]-=L[i][j]*y[j];
		y[i]=b[i]/L[i][i];
	}

	for (int i=N-1; i>=0; i--)
	{
		for (int j=i+1; j<N; j++) y[i]-=L[j][i]*x[j];
		x[i]=y[i]/L[i][i];
	}
	delete[] y;
	for (int i=0; i<N; i++) delete[] L[i];
	delete[] L;
	return;
}



/**
 * Метод прогонки
 */
void karchiganovaf::lab4()
{
	double* alph=new double[N];
	double* beta=new double[N];
	alph[0]=-A[0][1]/A[0][0];
	beta[0]=b[0]/A[0][0];
	for (int i=1; i<N; i++)
	{
		alph[i]=-A[i][i+1]/(A[i][i]+A[i][i-1]*alph[i-1]);
		beta[i]=(b[i]-A[i][i-1]*beta[i-1])/(A[i][i]+A[i][i-1]*alph[i-1]);
	}
	x[N-1]=beta[N-1];
	for (int i=N-2; i>=0; i--)
	{
		x[i]=alph[i]*x[i+1]+beta[i];
	}
	delete[] alph;
	delete[] beta;
	return;
}



/**
 * Метод Якоби
 */
void karchiganovaf::lab5()
{
	double eps=0.00001; // Точность нормы разности
	double* xlast=new double[N];
	for (int i=0; i<N; i++) xlast[i]=0;
	double* xnext;
	double delta_x;
	double axk=0;
	do
	{
		xnext=new double[N];
		delta_x=0;
		for (int i=0; i<N; i++)
		{
			axk=0;
			for (int k=0; k<i; k++) axk+=A[i][k]*xlast[k];
			for (int k=i+1; k<N; k++) axk+=A[i][k]*xlast[k];
			xnext[i]=(b[i]-axk)/A[i][i];
			delta_x+=pow(xnext[i]-xlast[i], 2);
		}
		delta_x=sqrt(delta_x);
		delete[] xlast;
		xlast=xnext;
	} while (delta_x>eps);
	x=xlast;
	return;
}



/**
 * Метод Зейделя
 */
void karchiganovaf::lab6()
{
	double eps=0.00001; // Точность нормы разности
	double* xlast = new double[N];
	for (int i=0; i<N; i++) xlast[i]=0;
	double* xnext;
	double delta_x;
	do
	{
		xnext=new double[N];
		delta_x=0;
		for (int i=0; i<N; i++)
		{
			xnext[i]=b[i];
			for (int k=0; k<i; k++) xnext[i]-=A[i][k]*xnext[k];
			for (int k=i+1; k<N; k++) xnext[i]-=A[i][k]*xlast[k];
			xnext[i]/=A[i][i];
			delta_x+=pow(xnext[i]-xlast[i], 2);
		}
		delta_x=sqrt(delta_x);
		delete[] xlast;
		xlast=xnext;
	} while (delta_x>eps);
	x=xlast;
}

double* karchiganovaf::Matrix_on_vector(double **M, double *V)
{
	double* result=new double[N];
	for (int i=0; i<N; i++)
	{
		result[i]=0;
		for (int j=0; j<N; j++)
			result[i]+=M[i][j]*V[j];
	}
	return result;
}

double karchiganovaf::scalar_of_vectors(double* v1, double* v2)
{
	double result=0;
	for (int i=0; i<N; i++) result+=(v1[i]*v2[i]);
	return result;
}

/**
 * Один из градиентных методов
 */
void karchiganovaf::lab7()
{
	double eps=0.00001; // Точность нормы разности
	double Tau=0;
	double sharpness=0;
	double* xlast=new double[N];
	for (int i=0; i<N; i++) xlast[i]=0;
	double* xnext;
	double *r=new double[N];
	double* Ax;
	double* Ar;
	do
	{
		xnext=new double[N];
		Ax=Matrix_on_vector(A,xlast);
		for (int i=0; i<N; i++) r[i]=Ax[i]-b[i];
		delete[] Ax;
		Ar=Matrix_on_vector(A, r);
		Tau=0;
		double temp1=scalar_of_vectors(r, r);
		double temp2=scalar_of_vectors(Ar, r);
		if (temp2==0) break;
		Tau=temp1/temp2;
	//	cout<<Tau<<endl;
		delete[] Ar;
		for (int i=0; i<N; i++) xnext[i]=xlast[i]-Tau*r[i];
		sharpness=0;
		for (int i=0; i<N; i++) sharpness=max(sharpness,abs(xnext[i]-xlast[i]));
		delete[] xlast;
		xlast=xnext;
	}
	while (sharpness>=eps);
	x=xlast;
	return;
}
