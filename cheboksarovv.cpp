#include "cheboksarovv.h"

/**
	* Метод Гаусса
	*/
void cheboksarovv::lab1()
{
 double koefc=0;
    for(int k=0;k<N;k++)
     {
      for(int i=k+1;i<N;i++)
      { 
       koefc=a[i][k]/a[k][k];
       for(int j=k;j<N;j++)
       {
        a[i][j]-=a[k][j]*koefc;  
       }
       x[i]=x[i]-koefc*x[k];
      }      
     }
     cout<<endl;
     x[N-1]=b[N-1];
     double summa=0;
     for(int i=N-2;i>=0;i--)
      {
       for(int j=i+1;j<N;j++){
        summa=summa+a[i][j]*x[j];}
        x[i]=(b[i]-summa)/a[i][i];
        summa=0; 
      }
}

void cheboksarovv::lab2()
{

}

void cheboksarovv::lab3()
{

}

void cheboksarovv::lab4()
{

}

void cheboksarovv::lab5()
{

}

void cheboksarovv::lab6()
{

}

void cheboksarovv::lab7()
{

}
