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
   virtual void lab8();

  double mskl(double *a, double *b);
  double* mvect(double **a, double *b);
  double* subsvect(double *a, double *b);
  double* numvect(double *a, double m);
  double** multMatr(double **a, double **b);
  double** transMatr(double **a);

};
