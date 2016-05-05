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
  double** L = new double*[N];
  for (int i=0; i<N; i++)
  L[i] = new double[N];
  double* y = new double[N];
  
   for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
     {L[i][j]=0;}
    
  for(int i=0;i<N;i++)
  {
   for(int k=0;k<=i-1;k++) 
    L[i][i]+=L[i][k]*L[i][k];
   L[i][i]=sqrt(A[i][i]-L[i][i]);
   for(int j=i+1;j<N;j++)
   {
    for(int k=0;k<=i-1;k++) 
     L[j][i]+=L[i][k]*L[j][k];
    L[j][i]=(A[i][j]-L[j][i])/L[i][i];
    } 
  } 
    double summa=0;
     for(int i=0;i<N;i++)
      {
       for(int j=0;j<i;j++){
        summa+=L[i][j]*y[j];}
       y[i]=(b[i]-summa)/L[i][i];
       summa=0;  
      }
     for(int i=N-1;i>=0;i--)
      {
       for(int j=i+1;j<N;j++){
        summa+=L[j][i]*x[j];}
       x[i]=(y[i]-summa)/L[i][i];
       summa=0;  
      }
      delete[] y;
}

void cheboksarovv::lab4()
{
  double* a2=new double[N];
 double* b2=new double[N];
    a2[0]=-A[0][1]/A[0][0];
    b2[0]=b[0]/A[0][0]; 
   for(int i=1;i<N;i++)
    {
     a2[i]=-A[i][i+1]/(A[i][i-1]*a2[i-1]+A[i][i]);
     b2[i]=(b[i]-A[i][i-1]*b2[i-1])/(A[i][i-1]*a2[i-1]+A[i][i]);        
    }
    x[N-1] = b2[N-1];
    for(int i=N-2; i>=0; i--)
     x[i] = a2[i]*x[i+1]+b2[i];
      delete[] a2;
      delete[] b2;
}

void cheboksarovv::lab5()
{
  double* a1=new double[N];
    double e=0.00000001;
    double n=e;
    while (n>=e)
    {
		for (int i=0;i<N;i++) 
        {
		 a1[i]=b[i];
		 for (int j=0;j<N;j++) 
         {
		  if (i!=j) a1[i]-=A[i][j]*x[j];
	 }
	     a1[i]/=A[i][i];
	}
       n=abs(x[0]-a1[0]);
		for (int k=0;k<N;k++) 
        {
		 if (abs(x[k]-a1[k])>n) n=abs(x[k]-a1[k]);
		 x[k]=a1[k];
	}
    }
 }

void cheboksarovv::lab6()
{   
    double* a1=new double[N];
    double e=0.000001;
    double n=0,v=0;
      for(int i=0;i<N;i++) {x[i]=0;}
   do
    {
	for (int i=0;i<N;i++) 
           a1[i]=x[i];
         
	for (int i=0;i<N;i++) 
         {
          v=0; 
          for(int j=0;j<i;j++)
           v+=(A[i][j]*x[j]);
          for(int j=i+1;j<N;j++)
           v+=(A[i][j]*a1[j]);
          x[i]=(b[i]-v)/A[i][i];  
          n=0;
	  for (int k=0;k<N;k++) 
          {n+=pow((x[k]-a1[k]),2);}	
         }	
    } while (sqrt(n)>=e);
	delete[] a1;
}

double cheboksarovv::uc(double *a, double *b) 
{
  double m=0;
  for (int i=0;i<N;i++)
   m+=a[i]*b[i];
  return m;       
} 
double* cheboksarovv::um(vector<vector<double> > a,double *b)
{
  double *x = new double [N];
  double m=0;
  for (int i=0; i<N; i++)
   {
    for (int j=0; j<N; j++)
       m+=a[i][j]*b[j];
       x[i]=m;
       m=0;
        }
    return x;
}
double* cheboksarovv::v(double *a, double *b)
 {
   double *x = new double [N];
      for (int i=0; i<N; i++)
         x[i]=a[i]-b[i];
     return x;
 }
double* cheboksarovv::umc( double *a,double b)
 {
     double *x = new double [N];
      for (int i=0; i<N; i++)
         x[i]=a[i]*b;
     return x;
 }
void cheboksarovv::lab7()
{
  double* a1=new double[N];
  double* a2=new double[N];
  double e=0.000001,n;
   for(int i=0;i<N;i++) {x[i]=0;a1[i]=0;}
    for(int i=0;i<N;i++) {fin>>b[i];x[i]=0;a1[i]=0;}  
    do{
       a2=v(um(A,x),b);
       a1=v(a1,umc(a2,uc(um(A,a2),a2)/uc(um(A,a2),um(A,a2))));
       n=abs(x[0]-a1[0]);
         for(int j=0;j<N;j++)
          {
            if (abs(x[j]-a1[j])>n) n=abs(x[j]-a1[j]);
            x[j]=a1[j];     
                 }   
            }while(n>e);
}
