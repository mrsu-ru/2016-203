#include "ArkunovIL.h"
#include<fstream>
#include<iostream>
#include<iomanip>
#include<cmath>

/**
 * Метод Гаусса
 */
void ArkunovIL::lab1()
{
    ifstream fin("input.txt");
  int n = 0;
 fin>>n;

 float m[n][n+1];
 float x[n];
 float s;

 for (int i=0;i<n;i++)
    for (int j=0;j<n+1;j++)
      fin>>m[i][j];


fin.close();


  for (int i = 0; i<n; i++)
   for (int j=i+1;j<n+1;j++){
    float d = m[j][i]/m[i][i];
    for (int k=0;k<n+1;k++)
      m[j][k]=m[j][k]-(m[i][k]*d);
   }

x[n]=0;

   for(int i=n;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<n;j++)
        s=s+m[i][j]*x[j];
      x[i]=(m[i][n]-s)/m[i][i];

    }


   ofstream fout("output.txt");

   for (int j = 0; j<n; j++){
	   fout<<x[j]<<' ';
   }
   fout.close();

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void ivanovii::lab2()
{
ifstream fin("input.txt");
  int n = 0;
 fin>>n;

 float m[n][n+1];
 float x[n];
 float s;

 for (int i=0;i<n;i++)
    for (int j=0;j<n+1;j++)
      fin>>m[i][j];


fin.close();

int maxi = 0;

for (int i = 1; i<n; i++)
    if (abs(m[i][0]) > abs(m[maxi][0])) maxi = i;

float p;
if (maxi != 0) {

   for (int i = 0; i<n+1; i++){
    p = m[0][i];
    m[0][i] = m[maxi][i];
    m[maxi][i] = p;
   }
}

  for (int i = 0; i<n; i++)
   for (int j=i+1;j<n+1;j++){
    float d = m[j][i]/m[i][i];
    for (int k=0;k<n+1;k++)
      m[j][k]=m[j][k]-(m[i][k]*d);
   }

x[n]=0;

   for(int i=n;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<n;j++)
        s=s+m[i][j]*x[j];
      x[i]=(m[i][n]-s)/m[i][i];

    }


   ofstream fout("output.txt");

   for (int j = 0; j<n; j++){
	   fout<<x[j]<<' ';
   }
   fout.close();
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void ivanovii::lab3()
{

}



/**
 * Метод прогонки
 */
void ivanovii::lab4()
{

}



/**
 * Метод Якоби
 */
void ivanovii::lab5()
{

}



/**
 * Метод Зейделя
 */
void ivanovii::lab6()
{

}



/**
 * Один из градиентных методов
 */
void ivanovii::lab7()
{

}
