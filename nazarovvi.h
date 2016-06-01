#pragma once
#include "lab.h"

class nazarovvi : public lab
{
  /**
   * ����� ������
   */
  virtual void lab1();
  /**
   * ����� ������ � ������� �������� ��������
   */
  virtual void lab2();
  /**
   * ����� ����������� ����� (����� ���������)
   */
  virtual void lab3();
  /**
   * ����� ��������
   */
  virtual void lab4();
  /**
   * ����� �����
   */
  virtual void lab5();
  /**
   * ����� �������
   */
  virtual void lab6();
  /**
   * ���� �� ����������� �������(����� ������������� ������)
   */
  virtual void lab7();
  /**
   * ��������� ������� �� ������
   */
  virtual void multiplication( double** M,  double* v,  double* r);
  /**
   * ��������� ������� �� �����
   */
  virtual void multiplication( double a,  double* v,  double* r);
  /**
   * ��������� ������� �� �������
   */
  virtual double** multiplication(double **a, double **b)
  /**
   * ��������� ������������ ��������
   */
  virtual double scale( double* v1,  double* v2);
  /**
   * �������� ��������
   */
  virtual void subtr( double* v1,  double* v2,  double* r);
  /**
   * ����� ��������
   */
  virtual void lab8();
};
