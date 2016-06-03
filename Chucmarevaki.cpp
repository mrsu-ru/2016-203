#include "Chucmarevaki.h"

/**
 * ����� ������
 */
void Chucmarevaki ::lab1()
{
    for (int k  = 0; k < N; k++)
    {
        for (int i = k + 1; i < N; i++)
        {
            double mu = A[i][k]/A[k][k];
            for(int j = 0; j < N; j++)
                 A[i][j] -= A[k][j]*mu;
            b[i] -= b[k] *mu;
        }
      }

     for (int m = N-1; m >= 0; m--)
     {
         double sum = 0;
         for(int i = N-1; i > m ; i--)
              sum  = sum + x[i]*A[m][i];
         x[m] = (b[m] - sum)/A[m][m];
     }
}


/**
 * ����� ������ � ������� �������� ��������
 */
void Chucmarevaki::lab2()
{
    float sum,c,max_el,l,l1;
int max_el_idx;
        max_el = abs(A[0][0]);
        max_el_idx = 0;
  for(int i = 1; i < N;i++)
    if (abs(A[i][0]) > max_el)
    {
        max_el = abs(A[i][0]);
        max_el_idx = i;
    };

 if (max_el_idx != 0)
 {
  for (int j = 0; j < N; j++)
    {
        l = A[0][j]; A[0][j] = A[max_el_idx][j]; A[max_el_idx][j] = l;
        l1 = b[0]; b[0] = b[max_el_idx]; b[max_el_idx] = l1;
     }
 }

 for (int i = 0; i < N; i++)
  for (int k = i + 1; k < N; k++)
  {
      c = A[k][i] / A[i][i];
      b[k] = b[k] - b[i]*c;
      for (int j = 0; j < n; j++)
        A[k][j] = A[k][j] - A[i][j]*c;
  }

  for(int i = N - 1; i >= 0; i--)
    {
        sum = 0;
  for(int j = i + 1; j < N; j++)
    sum = sum + A[i][j]*x[j];
  x[i] = (b[i] - sum) / A[i][i];
    }
}



/**
 * ����� ����������� ����� (����� ���������)
 */
void Chucmarevaki::lab3()
{
    float l[N][N],lt[N][N],d[N][N],c[N][N];
 float u[N];
 float s;


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
 * ����� ��������
 */
void Chucmarevaki::lab4()
{
     double* l=new double[N];
 double* m=new double[N];
 l[0]=-A[0][1]/A[0][0];
 m[0]=b[0]/A[0][0];
   for(int i=1;i<N;i++)
    {
 l[i]=-A[i][i+1]/(A[i][i-1]*l[i-1]+A[i][i]);
 m[i]=(b[i]-A[i][i-1]*m[i-1])/(A[i][i-1]*l[i-1]+A[i][i]);
    }
 x[N-1] = m[N-1];
    for(int i=N-1; i>=0; i--){
 x[i] = l[i]*x[i+1]+m[i];
    };
      delete[] l;
      delete[] m;

}



/**
 * ����� �����
 */
void Chucmarevaki::lab5()
{

}



/**
 * ����� �������
 */
void Chucmarevaki::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void Chucmarevaki::lab7()
{

}
