#include "timovkin.h"

/**
 * Метод Гаусса
 */
void timovkin::lab1()
{
<<<<<<< HEAD
double p;
for (int i = 0; i<N; i++)
for (int k=i+1;k<N;k++)
{
p=A[k][i]/A[i][i];
b[k]=b[k]-b[i]*p;
for (int j=0;j<N;j++)
A[k][j]=A[k][j]-A[i][j]*p;
}
for (int i = N-1; i>=0; i--)
for (int k=i-1;k>=0;k--)
{
p=A[k][i]/A[i][i];
b[k]=b[k]-b[i]*p;
for (int j=N-1;j>=0;j--)
A[k][j]=A[k][j]-A[i][j]*p;
}
for (int j = 0; j<N; j++)
x[j]=b[j]/A[j][j];
=======
for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }

 for (int i = N-1; i>=0; i--)
 for (int k=i-1;k>=0;k--)
 {
     c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=N-1;j>=0;j--)
     A[k][j]=A[k][j]-A[i][j]*c;

}
    for (int j=0; j<N; j++)
    {    x[j]=b[j]/A[j][j];}
>>>>>>> 30bd60ad65001884630ac0fcc3a240bc762f7fae
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void timovkin::lab2()
{
<<<<<<< HEAD
    for (int i = 0; i < N; i++)
        x[i] = b[i];
    double m,temp;
     int ii;
     for (int k = 0; k < N-1; k++)
        {
            ii = k;
            for (int i=k+1; i<N; i++)
                if(abs(A[i][k]) > abs(A[ii][k])) ii = i;
                temp=A[ii];
                A[k]=A[ii];
                A[k]=temp;
                temp=0;

                temp=b[ii];
                b[k]=b[ii];
                b[k]=temp;
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
void timovkin::lab3()
{
for(int i=0; i<N; i++){
		double s=0.0;
		for(int j=0; j<i-1; j++)
            {
			s+=l[i][j]*l[i][j];
		}
		l[i][i]=sqrt(A[i][i]-s);
		s=0.0;
		for(int k=i; k<N; k++){
			for(int j=0; j<i-1; j++){
				s+=l[k][j]*l[i][j];
			}
			l[k][i]=(A[k][i]-s)/l[i][i];
		}
	}
	for(int i=0; i<N; i++){
		double s = 0.0;
		for(int j=0; j<i; j++){
			s += l[i][j]*y[j];

		}
		y[i]=(f[i]-s)/l[i][i];
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<i; j++){
			std::swap(l[i][j], l[j][i]);
		}
	}
   for(int i=N-1; i>=0; i--){
		double s = 0.0;
		for(int j=i+1; j<N; j++){
			s += l[i][j]*x[j];
		}
		x[i]=(y[i]-s)/l[i][i];
	}
=======
  for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }
 for(int i=N;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+A[i][j]*x[j];
      x[i]=(b[i]-s)/A[i][i];
    }

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ivanovii::lab3()
{
>>>>>>> 30bd60ad65001884630ac0fcc3a240bc762f7fae

}



/**
 * Метод прогонки
 */
<<<<<<< HEAD
void ivanov::lab4()
=======
void ivanovii::lab4()
>>>>>>> 30bd60ad65001884630ac0fcc3a240bc762f7fae
{

}



/**
 * Метод Якоби
 */
<<<<<<< HEAD
void ivanov::lab5()
=======
void ivanovii::lab5()
>>>>>>> 30bd60ad65001884630ac0fcc3a240bc762f7fae
{

}



/**
 * Метод Зейделя
 */
<<<<<<< HEAD
void ivanov::lab6()
=======
void ivanovii::lab6()
>>>>>>> 30bd60ad65001884630ac0fcc3a240bc762f7fae
{

}



/**
 * Один из градиентных методов
 */
<<<<<<< HEAD
void ivanov::lab7()
=======
void ivanovii::lab7()
>>>>>>> 30bd60ad65001884630ac0fcc3a240bc762f7fae
{

}
