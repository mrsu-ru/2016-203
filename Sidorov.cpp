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





void Sidorov::lab2() {

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
