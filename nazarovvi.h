#pragma once
#include "lab.h"

class ivanovii : public lab
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
   * Один из градиентных методов(метод наискорейшего спуска)
   */
  virtual void lab7();
  /**
   * Умножение матрицы на вектор
   */
  virtual void multiplication( double** M,  double* v,  double* r);
  /**
   * Умножение вектора на число
   */
  virtual void multiplication( double a,  double* v,  double* r);
  /**
   * Умножение матрицы на матрицу
   */
  virtual double** multiplication(double **a, double **b)
  /**
   * Скалярное произведение векторов
   */
  virtual double scale( double* v1,  double* v2);
  /**
   * Разность векторов
   */
  virtual void subtr( double* v1,  double* v2,  double* r);
  /**
   * Метод вращения
   */
  virtual void lab8();
};
