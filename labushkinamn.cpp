#include "labushkinamn.h"

/**
 * Метод Гаусса
 */
void labushkinamn::lab1()
{
float c;
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
 for (int j = 0; j<N; j++)
    x[j]=b[j]/A[j][j];
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void labushkinamn::lab2()
{
float s,c,maxi,l,l1;
 int d;
 maxi=abs(A[0][0]);d=0;
 for(int i=1; i<N;i++)
   if (abs(A[i][0])>maxi)
      { maxi=abs(A[i][0]); d=i;};

if (d!=0)
{
  for (int j=0;j<N;j++)
   {
    l=A[0][j];    A[0][j]=A[d][j];    A[d][j]=l;
    l1=b[0];    b[0]=b[d];    b[d]=l1;
    }
}

for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }

 for(int i=N-1;i>=0;i--)
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
void labushkinamn::lab3()
{
float l[N][N],lt[N][N],d[N][N],c[N][N];
 float u[N];
 float s;
 for (int i = 0; i<N; i++)
     for (int j = 0; j<N; j++)
        {
         d[i][j]=0;
         l[i][j]=0;
         u[i]=0;
         x[i]=0;
         lt[i][j];
         c[i][j]=0;
        }

l[0][0]=sqrt(abs(A[0][0]));
d[0][0]=A[0][0]/A[0][0];

for(int i=1;i<N;i++)
 l[0][i]=A[i][0]/(d[0][0]*l[0][0]);

l[1][1]=sqrt(abs(A[1][1]-l[0][1]*l[0][1]*d[0][0]));
d[1][1]=(A[1][1]-l[0][1]*l[0][1]*d[0][0])/(A[1][1]-l[0][1]*l[0][1]*d[0][0]);

for(int i=2;i<N;i++)
 l[1][i]=(A[i][1]-l[0][i]*d[0][0]*l[0][1])/(d[1][1]*l[1][1]);

for (int i=2;i<N;i++)
{
  s=0;
  for (int p=0;p<i;p++)
    s=s+l[p][i]*l[p][i]*d[p][p];
  l[i][i]=sqrt(abs(A[i][i]-s));
  d[i][i]=(A[i][i]-s)/(A[i][i]-s);
}

for (int i=1;i<N;i++)
    for (int j=i+1;j<=N;j++)
{
  s=0;
float mi;
  if (i>j) mi=j;
     else mi=i;
  for (int p=0;p<=mi;p++)
        s=s+l[p][i]*l[p][j]*d[p][p];
  l[j][i]=(A[j][i]-s)/(l[i][i]*d[i][i]);
}
for (int i = 0; i<N; i++)
     for (int j = 0; j<N; j++)
        lt[j][i]=l[i][j];

for (int i=0; i<N; i++)
   {
      for (int j=0; j<N; j++)
		 {
			 s=0;
			 for (int p=0; p<N; p++)
				s=s+(l[i][p]*d[p][j]);
			 c[i][j]=s;
				}
   }

for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
{
  s=0;
  for (int p=0;p<N-1;p++)
        s=s+lt[i][p]*u[p];
  u[i]=(b[i]-s)/lt[i][i];
}

for (int i=N-1;i>=0;i--)
    for (int j=N-1;j>=0;j--)
{
  s=0;
  for (int p=N-1;p>0;p--)
        s=s+c[i][p]*x[p];
  x[i]=(u[i]-s)/c[i][i];
}
}



/**
 * Метод прогонки
 */
void labushkinamn::lab4()
{

}



/**
 * Метод Якоби
 */
void labushkinamn::lab5()
{

}



/**
 * Метод Зейделя
 */
void labushkinamn::lab6()
{

}



/**
 * Один из градиентных методов
 */
void labushkinamn::lab7()
{

}
