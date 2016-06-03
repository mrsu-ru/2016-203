
#include "godyaev.h"

/**
 * Метод Гаусса
 */
void godyaev::lab1()
{
double h;
for(int k=0; k<N; k++)
    for(int i=k+1; i<0;i++)
        {
            h = A[i][k] / A[k][k];
            b[i]-=b[k]*h; //изменяем столбец свободных членов параллельно с приведением матрицы А к треугольному виду
            for(int j=0;j<N;j++)
                {
                    A[i][j]=A[i][j]-A[k][j]*h;
                }
           }
for (int i = N-1; i>=0; i--)
 for (int k=i-1;k>=0;k--)
 {
   h=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*h;
   for (int j=N-1;j>=0;j--)
     A[k][j]=A[k][j]-A[i][j]*h;
 }
//Вычисление корней

for (int j = 0; j<N; j++)
    x[j]=b[j]/A[j][j];

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void godyaev::lab2()
{

double h;
	for (int k = 0; k<N - 1; k++)
		for (int i = k + 1; i<N; i++){
			double f1 = A[k][k];
			int flag = k;
			for (int j = k + 1; j<N; j++)
			{
				if (abs(A[j][k])>abs(f1)) {
					flag = j;
					f1 = A[j][k];
				}
			}
			for (int j = k; j<N; j++){
				std::swap(A[flag][j], A[k][j]);
			}
			std::swap(b[flag], b[k]);
			h = A[i][k] / A[k][k];
			b[i] = b[i] - h*b[k];
			for (int j = k; j<N; j++)
			{
				A[i][j] = A[i][j] - h*A[k][j];
			}
		}
	for (int i = N - 1; i >= 0; i--)
	{
		x[i] = b[i];
		for (int j = i + 1; j<N; j++)
		{
			x[i] = x[i] - A[i][j] * x[j];
		}
		x[i] = x[i]/A[i][i];
	}

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void godyaev::lab3()
{
	double** L = new double*[N], temp = 0;
	for (int i = 0; i<N; i++)
	{
		L[i] = new double[i + 1];
		temp= 0;
		for (int j = 0; j<i; j++)
		{
			temp = 0;
			for (int k = 0; k<j; k++)
				temp = temp+L[i][k] * L[j][k];
			L[i][j] = (A[i][j] - temp) / L[j][j];
		}
		temp = A[i][i];
		for (int k = 0; k<i; k++) temp =temp - L[i][k] * L[i][k];
		L[i][i] = sqrt(temp);
	}
	double* mas = new double[N];
	for (int i = 0; i<N; i++)
	{
		for (int j = i - 1; j >= 0; j--) b[i] =b[i]- L[i][j] * mas[j];
		mas[i] = b[i] / L[i][i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i + 1; j<N; j++)
			mas[i] -= L[j][i] * x[j];
		x[i] = mas[i] / L[i][i];
	}
	delete[] mas;
	for (int i = 0; i<N; i++)
		delete[] L[i];
	delete[] L;
}



/**
 * Метод прогонки
 */
void godyaev::lab4()
{
	double* AA = new double[N];
	double* BB = new double[N];

	AA[0] = A[0][1] / (-A[0][0]);
	BB[0] = b[0] / A[0][0];

	for (int i = 1; i<N; i++)
	{
		AA[i] = A[i][i + 1] / (-A[i][i - 1] * AA[i - 1] - A[i][i]);
		BB[i] = (-b[i] + A[i][i - 1] * BB[i - 1]) / (-A[i][i - 1] * AA[i - 1] - A[i][i]);
	}

	for (int i = N - 1; i >= 0; i--) 
		x[i] = AA[i] * x[i + 1] + BB[i];

	delete[] AA;
	delete[] BB;
}



/**
 * Метод Якоби
 */
void godyaev::lab5()
{
   double e=0.0000001;
   double flag=e;
   double* AA=new double[N];
   while(flag>=e)
       {
             for (int i=0;i<N;i++)
             {
                   AA[i]=b[i];
                   for (int j=0;j<N;j++)
                       {
                           if (i!=j)
                               AA[i]=AA[i]+A[i][j]*x[j];
                       }
             AA[i]=AA[i]/A[i][i];
             }
             flag=abs(x[0]-AA[0]);
            
             for (int k=0;k<N;k++)
             {
                 if (abs(x[k]-AA[k])>flag)
                     flag=abs(x[k]-AA[k]);
                 x[k]=AA[k];
             }
       }

}



/**
 * Метод Зейделя
 */
void godyaev::lab6()
{
	double e=0.0000001;
	double flag=e,flag2,s;
	while(flag>=e)
 	   {
   	      flag=0;
  	        for (int i=0;i<N;i++)
   	       {
   	           s=0;
   	             for (int j=0;j<N;j++)
   	                 {
   	                     if (i!=j)
        	                    s=s+A[i][j]*x[j];
                	    }
    	             flag2=x[i];
    	             x[i]=(b[i]-s)/A[i][i];
    	             flag=abs(x[i]-flag2);
    	      }
    	    }
}



/**
 * Один из градиентных методов
 */
void godyaev::lab7()
{

}
