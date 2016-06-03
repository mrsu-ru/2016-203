#include "Sidorov.h"
#include <iostream>


/*Метод Гаусса*/

void Sidorov::lab1()
{
	double coefficient = 0;
	for (int line = 1; line < N; line++)
  {
    for (int i = line; i < N; i++)
    {
      coefficient = matrix[i][line-1] / matrix[line-1][line-1];
      for (int j = line; j < N; j++)  
        matrix[i][j] -= coefficient * matrix[line-1][j];
        
      b[i] = b[i] - coefficient * b[line-1];
    } 
  } 
   
  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < N; j++)
      b[i] = b[i] - A[i][j] * x[j];
       
    x[i] = b[i] / A[i][i];
  } 
 
  return;
}





void Sidorov::lab2() 
{
	double coefficient;
	int max;

    for (int k=0; k<N-1; k++)
    {
      max = k;
      for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[max][k])) max = i;
        std::swap(A[max], A[k]);
        std::swap(b[max], b[k]);

        for (int i=k+1; i<N; i++)
        {

          coefficient = A[i][k]/A[k][k];
          for (int j=k; j<N; j++)
            A[i][j] = A[i][j] - coefficient*A[k][j];
          b[i] = b[i] - coefficient*b[k];
        }
    }


    for(int i = 0; i<N; i++)
    {
      x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--)
    {
      for (int j=i+1;j<N;j++)
        x[i] = x[i] - A[i][j]*x[j];
      x[i] = x[i] / A[i][i];
    }
}

void Sidorov::lab3() {

}

void Sidorov::lab4() {
  
}

void Sidorov::lab5() {

}

void Sidorov::lab6() {

}

void Sidorov::lab7() {

}
