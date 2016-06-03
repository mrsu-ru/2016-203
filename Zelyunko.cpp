#include "zelyunko.h"

/**
 * Метод Гаусса
 */

void Zelyunko ::lab1()
{
    double z=0;

for(int i=0;i<N;i++)
{
    for(int k=i+1;k<N;k++)
    {
        z=-A[k][i]/A[i][i];

        for(int g=0;g<N;g++)
        {
            A[k][g]=A[k][g]+z*A[i][g];
        }
        b[k]=b[k]+z*b[i];
    }
}

//Вычисление корней
 //z- используется для нахожения i-ого неизвестного за счет уже найденных N-i неизвестных

 for(int i=N-1;i>=0;i--)
{
    z=0;

    for(int g=N-1;g>i;g--)
    {
     z+=A[i][g]*x[g];
    }

  x[i]=(b[i]-z)/A[i][i];
}
}


/**
 * Метод Гаусса с выбором главного элемента
 */
 void MESwMR(double** A, double* b, int RowIndex, int N)
{
 double MaxElement=A[RowIndex][RowIndex];
 int MaxElementIndex=RowIndex;

 for(int i=RowIndex+1;i<N;i++)
 {
     if(A[i][RowIndex]>MaxElement)
     {
         MaxElement=A[i][RowIndex];
          MaxElementIndex=i;
     }
 }

 if(MaxElementIndex!=RowIndex)
 {
     //To save memory space we will use MaxElement as a bufer.

     for(int i=0;i<N;i++)
     {
       MaxElement=A[RowIndex][i];
        A[RowIndex][i]=A[MaxElementIndex][i];
         A[MaxElementIndex][i]=MaxElement;
     }
 }
}
void Zelyunko::lab2()
{
    double z=0;

for(int i=0;i<N;i++)
{
    MESwMR(A,b,i,N);
    for(int k=i+1;k<N;k++)
    {
        z=-A[k][i]/A[i][i];

        for(int g=0;g<N;g++)
        {
            A[k][g]=A[k][g]+z*A[i][g];
        }
        b[k]=b[k]+z*b[i];
    }
}


//Вычисление корней
 //z- используется для нахожения i-ого неизвестного за счет уже найденных N-i неизвестных

 for(int i=N-1;i>=0;i--)
{
    z=0;

    for(int g=N-1;g>i;g--)
    {
     z+=A[i][g]*x[g];
    }

  x[i]=(b[i]-z)/A[i][i];
}
}



/**
 * Метод квадратного корня (метод Холецкого)
 */

 int SignArg(double z)
{
    if(z>0)return(1);
    if(z<0)return(-1);
    if(z==0)return(0);
}

void Trans (double** S,int N)
{
    double** Strans=new double*[N];
    for(int i=0;i<N;i++) Strans[i]=new double[N];

    for(int i=0;i<N;i++)
    {
        for(int g=0;g<N;g++)
        {
            Strans[g][i]=S[i][g];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int g=0;g<N;g++)
        {
            S[i][g]=Strans[i][g];
        }
    }
}

void Specialmult(double** S,int** D,int N)
{
  for(int i=0;i<N;i++)
  {
      for(int g=0;g<N;g++)
      {
          S[i][g]=S[i][g]*D[g][g];
      }
  }
}
void Zelyunko::lab3()
{
    double** S=new double*[N];
    int** D=new int*[N];
    double* y=new double[N];

    for(int i=0;i<N;i++)
    {
        S[i]=new double[N];
        D[i]=new int[N];
    }

    for(int i=0;i<N;i++)
    {
        for(int g=0;g<N;g++)
        {
            D[i][g]=0;
            S[i][g]=0;
        }
    }

    double z=0;
    double s=0;
    	for (int i = 0; i < N; i++)
    {
        for(int g=0; g<i; g++)
            s+=S[i][g]*S[i][g];

        S[i][i]=sqrt(A[i][i]-s);
        s = 0;

        for(int g=i+1; g < N; g++)
        {
            for (int k=0; k<i; k++)
                s+=S[i][k]*S[g][k];

            S[g][i] = (A[g][i]-s)/S[i][i];
            s = 0;
        };
    }
/*
  for(int i=0; i<N;i++)
  {
      z=0;
      for(int k=0;k<i;k++)
      {
          z+=pow(S[i][k],2);//*D[k][k];
      }
      z=A[i][i]-z;
      //D[i][i]=SignArg(z);
       S[i][i]=sqrt(abs(z));


       for(int g=i+1;g<N;g++)
       {
         z=0;
         for(int k=0;k<i;k++)
         {
           z+=S[i][k]*S[g][k];//*D[k][k];
         }
         z=A[i][g]-z;
         S[g][i]=z/S[i][i];//*D[i][i];
       }
  }*/
 //Specialmult(S,D,N);
 //Trans(S,N);

for(int i=0;i<N;i++)
{
  z=0;
   for(int g=0;g<i;g++)
   {
       z+=S[i][g]*y[g];
   }
   y[i]=(b[i]-z)/S[i][i];
}


for(int i=N-1;i>=0;i--)
{
    z=0;

    for(int g=i+1;g<N;g++)
    {
     z+=S[g][i]*x[g];
    }

  x[i]=(y[i]-z)/S[i][i];
}
}




/**
 * Метод прогонки
 */
void Zelyunko::lab4()
{
 double* P=new double[N-1];
 double* Q=new double[N];
 double q=0;
 P[0]=A[0][1]/-A[0][0];//Находим первноначальные значения
 Q[0]=-b[0]/-A[0][0];

 for(int i=1;i<N-1;i++)
 {
     q=-A[i][i]-A[i+1][i]*P[i-1];
     P[i]=A[i][i+1]/q;
     Q[i]=(A[i+1][i]*Q[i-1]-b[i])/q;
 }
 Q[N-1]=(A[N-1][N-2]*Q[N-2]-b[N-1])/(A[N-1][N-1]-A[N-1][N-2]*P[N-2]);
 x[N-1]=Q[N-1];

 for(int i=N-2;i>=0;i--)
 {
  x[i]=P[i]*x[i+1]+Q[i];
 }
}



/**
 * Метод Якоби
 */
void Zelyunko::lab5()
{

}



/**
 * Метод Зейделя
 */
void Zelyunko::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Zelyunko::lab7()
{

}
