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
     for(int g=0;g<N;g++) {m=A[j][g];A[j][g]=A[index][g];A[index][g]=m;m=b[j]; b[j]=b[index];b[index]=m;}
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

double* cheboksarovv::umc( double *x,double y)
 {
 double *z = new double [N];
 for (int i=0; i<N; i++) z[i]=x[i]*y;
     return z; 
     }
double cheboksarovv::uc(double *x, double *y) 
{
  double z=0;
  for (int i=0;i<N;i++) z+=x[i]*y[i];
  return z;       
} 
double* cheboksarovv::v(double *x, double *y)
 {
   double *z = new double [N];
      for (int i=0; i<N; i++) z[i]=x[i]-y[i];
     return z;
 }
double* cheboksarovv::um(double **x,double *y)
{
  double *z = new double [N];
  double q=0;
  for (int i=0; i<N; i++)
   {for (int j=0; j<N; j++) q+=x[i][j]*y[j];
    z[i]=q;
    q=0;}
    return z;
}
 bool cheboksarovv::logik(double *x,double *y,double e)
 {
  double n=abs(x[0]-y[0]);
   for(int j=0;j<N;j++)
          {
            if (abs(x[j]-y[j])>n) n=abs(x[j]-y[j]);
            x[j]=y[j];     
                 }   
  if (n>=e) return true;
  else return false;               
      }
void cheboksarovv::lab7()
{ double* a1=new double[N];
  double* a2=new double[N];
  double e=0.00000001;
   do{
       a2=v(um(A,x),b);
       a1=v(a1,umc(a2,uc(um(A,a2),a2)/uc(um(A,a2),um(A,a2))));
            }while(logik(x,a1,e));
}

double** cheboksarovv::t(double **x)
{
  double **z = new double *[N];
  for(int i=0; i<N; i++) {z[i] = new double [N];}  
   for(int i=0; i<N; i++) 
      for(int j=0; j<N; j++) { z[i][j]=x[j][i];}
      return z;
}
double** cheboksarovv::um1(double **x,double **y)
{
  double q=0;
  double **z = new double *[N];
   for(int i=0; i<N; i++) {z[i] = new double [N];}
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
       q=0;
        for(int j1=0; j1<N; j1++) { q+=x[i][j1]*y[j1][j];}
       z[i][j] = q;
      }
     }
     int y1=0;
     return z;
    }
void cheboksarovv::lab8()
{
	double e=0.01;
        double m=0,s=0;
        double **u = new double *[N];   
        for(int i=0; i<N; i++) {u[i] = new double [N];}   
        double fi=0;  
        int i1=0,j1=0;
 do
 {  
     m=0;
     s=0;
     for(int i=0;i<N;i++){
      for(int j=0;j<N;j++) {if ((abs(A[i][j])>m)&&(i!=j)) {m=abs(A[i][j]);i1=i;j1=j;}}}
      fi=0.5*(atan(2*m/(A[i1][i1]-A[j1][j1])));
      if (A[i1][i1]==A[j1][j1]) fi=3.14/4;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    {u[i][i]=1;if (i!=j) u[i][j]=0;}
    u[j1][i1]=sin(fi);u[i1][i1]=cos(fi);u[j1][j1]=cos(fi);u[i1][j1]=-sin(fi);
    A=um1(um1(t(u),A),u);
    for(int i=0;i<N;i++)
     for(int j=1;j<N;j++)
    if ((i!=j)&&(j>i)) s+=A[i][j]*A[i][j];
    s=sqrt(s);
  } while (s>e);
  for(int i=0;i<N;i++) x[i]=A[i][i];
}
