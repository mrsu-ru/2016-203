#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <locale>
#include <stdlib.h>
int main ()
{
    int n=100,i,j,k,m,l,z,t, index;
    double a[n][n],b[n],x[n],y,g;
    using std::swap;
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
m=a[0][0];
index=0;

 for (k=0;k<n;k++)
    {


        for (l=k;l<n;l++)
        {
        if (abs(a[l][k])>m)
        {
            index=l;
            m=abs(a[l][k]);
        }
        }
        for (j=k;j<n;j++)
        {
        swap(a[k][j],a[index][j]);
        swap(b[k],b[index]);
        }
    }

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
              for(z=0;z<n;z++)
            {
                for(t=0;t<n;t++)
                {
                    fprintf(p,"%lf ",a[z][t]);
                }
                fprintf(p,"\n");
            }
            fprintf(p,"\n");

        }


    }

//Нахождение корней

        for( i=n-1;i>=0;i--)
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
