
#include "godyaev.h"

/**
 * Метод Гаусса
 */
void godyaev::lab1()
{
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

}



/**
 * Метод прогонки
 */
void godyaev::lab4()
{

}



/**
 * Метод Якоби
 */
void godyaev::lab5()
{

}



/**
 * Метод Зейделя
 */
void godyaev::lab6()
{

}



/**
 * Один из градиентных методов
 */
void godyaev::lab7()
{

}
