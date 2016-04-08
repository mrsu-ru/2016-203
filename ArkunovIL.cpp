#include "ArkunovIL.h"
#include<iostream>
#include<iomanip>
#include<cmath>

/**
 * ����� ������
 */
void ArkunovIL::lab1()
{



 float s;

     for (int j=0;j<N;j++)
      A[j][n]=b[j];


  for (int i = 0; i<N; i++)
   for (int j=i+1;j<N+1;j++){
    float d = A[j][i]/A[i][i];
    for (int k=0;k<N+1;k++)
      A[j][k]=A[j][k]-(A[i][k]*d);
   }

x[N]=0;

   for(int i=N;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+A[i][j]*x[j];
      x[i]=(A[i][N]-s)/A[i][i];

    }

}


/**
 * ����� ������ � ������� �������� ��������
 */
void ArkunovIL::lab2()
{
 float s;

     for (int j=0;j<N;j++)
      A[j][n]=b[j];


int maxi = 0;

for (int i = 1; i<N; i++)
    if (abs(A[i][0]) > abs(A[maxi][0])) maxi = i;

float p;
if (maxi != 0) {

   for (int i = 0; i<N+1; i++){
    p = A[0][i];
    A[0][i] = A[maxi][i];
    A[maxi][i] = p;
   }
}

  for (int i = 0; i<N; i++)
   for (int j=i+1;j<N+1;j++){
    float d = A[j][i]/A[i][i];
    for (int k=0;k<N+1;k++)
      A[j][k]=A[j][k]-(A[i][k]*d);
   }

x[N]=0;

   for(int i=N;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+A[i][j]*x[j];
      x[i]=(A[i][N]-s)/A[i][i];

    }
}



/**
 * ����� ����������� ����� (����� ���������)
 */
void ArkunovIL::lab3()
{

}



/**
 * ����� ��������
 */
void ArkunovIL::lab4()
{

}



/**
 * ����� �����
 */
void ArkunovIL::lab5()
{

}



/**
 * ����� �������
 */
void ArkunovIL::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void ArkunovIL::lab7()
{

}
