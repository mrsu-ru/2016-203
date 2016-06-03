#include "Sukhova.h"

/**
 * ����� ������
 */
void Sukhova::lab1(){

//���������� � ����� ������������ ���� ������� A
float q=0; //������������� ��� �������������� ������������, �� ������� �� ��������� ������ ��� ���������� ������ � � ������������ ����
    for(int k=0; k<N; k++)
        for(int i=k+1; i<N;i++)
           {
               q=(A[i][k]/A[k][k]);
               b[i]-=b[k]*q; //�������� ������� ��������� ������ ����������� � ����������� ������� � � ������������ ����
            for(int j=0;j<N;j++)
                {
                    A[i][j]=A[i][j]-A[k][j]*q;

                }
           }


//���������� ������
double s=0; //s- ������������ ��� ��������� i-��� ������������ �� ���� ��� ��������� N-i �����������

    for(int i=N-1;i>=0;i--)
    {

        for (int j=i+1; j<N;j++)
            s=s+A[i][j]*x[j];
        x[i]=(b[i]-s)/A[i][i];
        s=0;

    }
}

/**
 * ����� ������ � ������� �������� ��������
 */
void Sukhova::lab2()
{
//находим максимальный элемент в столбце
for (int k = 0; k < N; k++)
  	{
  		double max = abs(A[k][k]);
          int index = k;
          for (int i = k+1; i < N; i++)
  		{
  			if (abs(A[i][k]) > max)
  			{
  				max = abs(A[i][k]);
  				index = i;
  			}
  		}
  		//меняем строчки
  		for (int j = 0; j < N; j++) swap(A[k][j], A[index][j]);
  		swap(b[k], b[index]);

  		for (int i = k; i < N; i++)
  		{
  			double temp = A[i][k];
  			if (temp == 0) continue;
  			for (int j = 0; j < N; j++) A[i][j] = A[i][j] / temp;
  			b[i] = b[i] / temp;
  			if (i == k) continue;
  			for (int j = 0; j < N; j++) {A[i][j] = A[i][j] - A[k][j];}

  			b[i] = b[i] - b[k];

  		}
  	}
  	for (int k = N-1; k >= 0; k--)
  	{
  		x[k] = b[k];
  		for (int i = 0; i < k; i++) b[i] = b[i] - A[i][k] * x[k];
  	}

}



/**
 * ����� ����������� ����� (����� ���������)
 */
void Sukhova::lab3()
{
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

	double sum = 0;
	for (int i = 0; i<N; i++)
	{
		for (int k = 0; k <= i - 1; k++)
			sum += L[i][k] * L[i][k];

		L[i][i] = sqrt(A[i][i] - sum);
		sum = 0;
		for (int j = i + 1; j<N; j++)
			{
				for (int k = 0; k <= i - 1; k++)
					sum += L[i][k] * L[j][k];

				L[j][i] = (A[i][j] - sum) / L[i][i];
				sum = 0;
			}
	}

	for (int i = 0; i<N; i++)
	{
		sum = 0;
		for (int j = 0; j<i; j++)
			sum += L[i][j] * y[j];

		y[i] = (b[i] - sum) / L[i][i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		sum = 0;
		for (int j = i + 1; j<N; j++)
			sum += L[j][i] * x[j];

		x[i] = (y[i] - sum) / L[i][i];
	}
    delete[] y;
	for (int i = 0; i<N; i++)
		delete[] L[i];
	delete[] L;
}
}



/**
 * ����� ��������
 */
void Sukhova::lab4()
{
	double* a=new double[N];
	double* b=new double[N];
	a[0]=-A[0][1]/A[0][0];
	b[0]=b[0]/A[0][0];
	for (int i=1; i<N; i++)
	{
		a[i]=-A[i][i+1]/(A[i][i]+A[i][i-1]*a[i-1]);
		b[i]=(b[i]-A[i][i-1]*b[i-1])/(A[i][i]+A[i][i-1]*a[i-1]);
	}
	x[N-1]=b[N-1];
	for (int i=N-2; i>=0; i--)
	{
		x[i]=a[i]*x[i+1]+b[i];
	}
	delete[] a;
	delete[] b;
	return;
}



/**
 * ����� �����
 */
void Sukhova::lab5()
{

}



/**
 * ����� �������
 */
void Sukhova::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void Sukhova::lab7()
{

}
