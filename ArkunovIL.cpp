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

x[N]=0;

   for(int i=N;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+W[i][j]*x[j];
      x[i]=(W[i][N]-s)/W[i][i];
}
}

/**
 * ����� ������ � ������� �������� ��������
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

x[N]=0;

   for(int i=N-1;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+W[i][j]*x[j];
      x[i]=(W[i][N]-s)/W[i][i];

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
