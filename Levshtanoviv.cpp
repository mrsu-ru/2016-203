#include "Levshtanoviv.h"

std::string Levshtanoviv::get_name()
{
  return std::string("Levshtanoviv");
}


/**
 * Метод Гаусса
 */
void Levshtanoviv::lab1()
{
for (int k = 0; k<N; k++)
     for (int i=k+1;i<N;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }

     for (int k = N-1; k>=0; k--)
     for (int i=k-1;i>=0;i--)
      for (int j=N-1;j>=0;j--)
 {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }
      for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        if (i==j) x[i]=b[i]/A[i][j];
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Levshtanoviv::lab2()
{
  float s,c,ma,l,l1;
 int p;
 ma=abs(A[0][0]);int d=0;
 for(int i=1; i<N;i++)
   if (abs(A[i][0])>ma)
      { ma=abs(A[i][0]); d=i;};

if (p!=0)
{
  for (int j=0;j<N;j++)
   {
    l=A[0][j];    A[0][j]=A[d][j];    A[d][j]=l;
    l1=b[0];    b[0]=b[p];    b[p]=l1;
    }
}
for (int k = 0; k<N; k++)
     for (int i=k+1;i<N;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }


      for(int i=N-1; i>=0; i--)

      {s=0;
          for(int j=i+1; j<=N; j++)
             s=s+A[i][j]*x[j];
         x[i]=(b[i]-s)/(A[i][i]);
      }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Levshtanoviv::lab3()
{
     float D[N][N], min_i_j, sum;
     float S[N][N], tS[N][N], u[N], qq[N][N];
      S[0][0]=sqrt(A[0][0]);
      D[0][0]=A[0][0]/A[0][0];

      for (int j=1; j<N; j++)
          S[0][j]=A[j][0]/(S[0][0]*D[0][0]);

      S[1][1]=sqrt(A[1][1]-S[0][1]*S[0][1]*D[0][0]);
      D[1][1]=(A[1][1]-S[0][1]*S[0][1]*D[0][0])/(A[1][1]-S[0][1]*S[0][1]*D[0][0]);

      for (int i=2; i<N; i++)
        S[1][i]=(A[i][1]-S[0][i]*S[0][1]*D[0][0])/(D[1][1]*S[1][1]);

      for(int i=2; i<N; i++)
      {
          sum=0;
          for (int k=0; k<i; k++)
            sum=sum+S[k][i]*S[k][i]*D[k][k];
          S[i][i]=sqrt(A[i][i]-sum);
          D[i][i]=(A[i][i]-sum)/(A[i][i]-sum);

      }


      for(int i=1; i<N; i++)
        for(int j=i+1; j<=N; j++)
      {float sum=0;
          if(i>j) min_i_j=j;
            else min_i_j=i;


          for (int k=0; k<=min_i_j; k++)
            sum=sum+S[k][i]*S[k][j]*D[k][k];
          S[i][j]=(A[j][i]-sum)/(D[i][i]*S[i][i]);
      }

      for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
           tS[i][j]=S[j][i];

      for (int i=0; i<N; i++)
      {
         for (int j=0; j<N; j++)
		 {
			 sum=0;
			 for (int k=0; k<N; k++)
				sum=sum+(S[i][k]*D[k][j]);
			 qq[i][j]=sum;
   	     }
      }

      for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
        {
           sum=0;
           for (int k=0;k<N-1;k++)
              sum=sum+tS[i][k]*u[k];
           u[i]=(b[i]-sum)/tS[i][i];
        }

        for (int i=N-1;i>=0;i--)
          for (int j=N-1;j>=0;j--)
          {
             sum=0;
             for (int k=N-1;k>0;k--)
                sum=sum+qq[i][k]*x[k];
             x[i]=(u[i]-sum)/qq[i][i];
          }

        
}



/**
 * Метод прогонки
 */
void Levshtanoviv::lab4()
{
  double* k=new double[N];
 double* k1=new double[N];
    k[0]=-A[0][1]/A[0][0];
    k1[0]=b[0]/A[0][0];
   for(int i=1;i<N;i++)
    {
     k[i]=-A[i][i+1]/(A[i][i-1]*k[i-1]+A[i][i]);
     k1[i]=(b[i]-A[i][i-1]*k1[i-1])/(A[i][i-1]*k[i-1]+A[i][i]);
    }
    x[N-1] = k1[N-1];
    for(int i=N-1; i>=0; i--){
     x[i] = k[i]*x[i+1]+k1[i];
    };
      delete[] k;
      delete[] k1;

}



/**
 * Метод Якоби
 */
void Levshtanoviv::lab5()
{

}



/**
 * Метод Зейделя
 */
void Levshtanoviv::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Levshtanoviv::lab7()
{

}
