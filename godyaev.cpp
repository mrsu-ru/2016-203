
#include "godyaev.h"
>>>>>>> 63233f1921784a4082828cd37426c15c332aed78

/**
 * Метод Гаусса
 */
void godyaev::lab1()
{
for(int k=0; k<N; k++)
        for(int i=k+1; i<N;i++)
           {
               b[i]-=b[k]*(A[i][k]/A[k][k]);; //изменяем столбец свободных членов параллельно с приведением матрицы А к треугольному виду
            for(int j=0;j<N;j++)
                {
                    A[i][j]=A[i][j]-A[k][j]*(A[i][k]/A[k][k]);;
                }
           }
//Вычисление корней
double z=0; //z- используется для нахожения i-ого неизвестного за счет уже найденных N-i неизвестных

 for(int i=N-1;i>=0;i--)
{
    z=0;

    for(int g=N-1;g>i;g--)
    {
     z+=A[i][g]*b[g];
    }


  X[i]=double((b[i]-z)/A[i][i]);

}
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
				swap(A[flag][j], A[k][j]);
			}
			swap(b[flag], b[k]);
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
