#include "ArkunovIL.h"

/**
 * Метод Гаусса
 */
void ArkunovIL::lab1()
{

 float s;
 float W[N][N+1];

  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
      W[i][j] = A[i][j];


     for (int j=0;j<N;j++)
      W[j][N]=b[j];


  for (int i = 0; i<N; i++)
   for (int j=i+1;j<N+1;j++){
    float d = W[j][i]/W[i][i];
    for (int k=0;k<N+1;k++)
      W[j][k]=W[j][k]-(W[i][k]*d);
   }

x[N-1]=0;

   for(int i=N-1;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+W[i][j]*x[j];
      x[i]=(W[i][N]-s)/W[i][i];
}
}

/**
 * Метод Гаусса с выбором главного элемента
 */
void ArkunovIL::lab2()
{
 float s;
 float W[N][N+1];

  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
      W[i][j] = A[i][j];


     for (int j=0;j<N;j++)
      W[j][N]=b[j];

int maxi = 0;

for (int i = 1; i<N; i++)
    if (abs(W[i][0]) > abs(W[maxi][0])) maxi = i;

float p;
if (maxi != 0) {

   for (int i = 0; i<N+1; i++){
    p = W[0][i];
    W[0][i] = W[maxi][i];
    W[maxi][i] = p;
   }
}

  for (int i = 0; i<N; i++)
   for (int j=i+1;j<N+1;j++){
    float d = W[j][i]/W[i][i];
    for (int k=0;k<N+1;k++)
      W[j][k]=W[j][k]-(W[i][k]*d);
   }

x[N-1]=0;

   for(int i=N-1;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+W[i][j]*x[j];
      x[i]=(W[i][N]-s)/W[i][i];

    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ArkunovIL::lab3()
{
    float D[N][N], min, sum;
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
          if(i>j) min=j;
            else min=i;


          for (int k=0; k<=min; k++)
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
void ArkunovIL::lab4()
{
     double* k=new double[N];
 double* p=new double[N];
    k[0]=-A[0][1]/A[0][0];
    p[0]=b[0]/A[0][0];
   for(int i=1;i<N;i++)
    {
     k[i]=-A[i][i+1]/(A[i][i-1]*k[i-1]+A[i][i]);
     p[i]=(b[i]-A[i][i-1]*p[i-1])/(A[i][i-1]*k[i-1]+A[i][i]);
    }
    x[N-1] = p[N-1];
    for(int i=N-1; i>=0; i--){
     x[i] = k[i]*x[i+1]+p[i];
    };
      delete[] k;
      delete[] p;


}



/**
 * Метод Якоби
 */
void ArkunovIL::lab5()
{

}



/**
 * Метод Зейделя
 */
void ArkunovIL::lab6()
{

}



/**
 * Один из градиентных методов
 */
void ArkunovIL::lab7()
{

}
