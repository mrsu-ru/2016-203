#include <stdio.h>
#include <fstream>
#include <iostream>
int main ()
{
    int n=100,i,j,k;
    double a[n][n],b[n],x[n],y;
FILE *f;
FILE *p;
f=fopen("input.txt","r");
p=fopen("output.txt","w");
fscanf(f,"%d/n",&n);
   for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
      {
       fscanf(f,"%lf",&a[i][j]);
      }
    }

    for(i=0;i<n;i++)
        {
 fscanf(f,"%lf",&b[i]);
    }

//  Привидение к треугольному виду
 for (k=0;k<n;k++)
    {
        for(i=k+1;i<n;i++)
        {
            y=a[i][k]/a[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<n;j++)
            {
                a[i][j]-=a[k][j]*y;
            }
        }
    }
//Нахождение корней

        for(i=n-1;i>=0;i--)
        {

            x[i]=b[i]/a[i][i];
            for(j=i+1;j<n;j++)
            {
                x[i]+=-a[i][j]*x[j]/a[i][i];
            }
        }

//Вывод матрицы в файл
    for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
      {
       fprintf(p,"%lf ",a[i][j]);
      }
    fprintf(p,"\n");
    }

for(i=0;i<n;i++)
    {
    fprintf(p,"%lf ",b[i]);
    }
fprintf(p,"\n");

for(i=0;i<n;i++)
    {
    fprintf(p,"%lf ",x[i]);
    }

fclose(f);
fclose(p);
}
