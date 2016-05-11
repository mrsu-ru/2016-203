#pragma once
#include "lab.h"

class ploduhindm : public lab
{
  /**
   * Метод Гаусса
   */
  virtual void lab1();
  /**
   * Метод Гаусса с выбором главного элемента
   */
  virtual void lab2();
  /**
   * Метод квадратного корня (метод Холецкого)
   */
  virtual void lab3();
  /**
   * Метод прогонки
   */
  virtual void lab4();
  /**
   * Метод Якоби
   */
  virtual void lab5();
  /**
   * Метод Зейделя
   */
  virtual void lab6();
  /**
   * Один из градиентных методов
   */
  virtual void lab7();

  long double mskl(long double *a, long double *b);
  long double* mvect(long double **a, long double *b);
  long double* subsvect(long double *a, long double *b);
  long double* numvect(long double *a, long double m);

};
