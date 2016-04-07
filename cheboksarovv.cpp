#include "cheboksarovv.h"

/**
	* Ìåòîä Ãàóññà
	*/
void cheboksarovv::lab1()
{
 double koefc=0;
    for(int k=0;k<N;k++)
     {
      for(int i=k+1;i<N;i++)
      { 
       koefc=A[i][k]/A[k][k];
       for(int j=k;j<N;j++)
       {
        A[i][j]-=A[k][j]*koefc;  
       }
       b[i]-=koefc*b[k];
      }      
     }
     double summa=0;
     for(int i=N-1;i>=0;i--)
      {
       for(int j=i+1;j<N;j++){
        summa=summa+A[i][j]*x[j];}
        x[i]=(b[i]-summa)/A[i][i];
        summa=0; 
      }
}

void cheboksarovv::lab2()
{
 double max=A[0][0],m=0,summa=0,koefc=0; 
   int index=0;
   for(int j=0;j<N;j++)
    {
     for(int i=j;i<N;i++){if (abs(A[i][j])>max) {max=abs(A[i][j]);index=i;}}
     for(int g=0;g<N;g++) {m=A[j][g];a[j][g]=A[index][g];A[index][g]=m;m=b[j]; b[j]=b[index];b[index]=m;}    
     max=0;
    }
      
    for(int k=0;k<N;k++)
      for(int i=k+1;i<N;i++)
      { 
       koefc=A[i][k];
       for(int j=k;j<N;j++) A[i][j]-=A[k][j]*koefc/A[k][k];  
       b[i]-=koefc*b[k]/A[k][k];
      }      
     for(int i=N-1;i>=0;i--)
      {
             
       for(int j=i+1;j<N;j++){
        summa=summa+A[i][j]*x[j];}
        x[i]=(b[i]-summa)/A[i][i];
        summa=0; 
      }
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
