#pragma once
#include "lab.h"

class cheboksarovv: public lab
{
  /**
	* Ìåòîä Ãàóññà
	*/
  virtual void lab1();
 /**
	* Ìåòîä Ãàóññà ñ âûáîðîì ãëàâíîãî ýëåìåíòà
	*/
  virtual void lab2();
  /**
   * ÐœÐµÑ‚Ð¾Ð´ ÐºÐ²Ð°Ð´Ñ€Ð°Ñ‚Ð½Ð¾Ð³Ð¾ ÐºÐ¾Ñ€Ð½Ñ (Ð¼ÐµÑ‚Ð¾Ð´ Ð¥Ð¾Ð»ÐµÑ†ÐºÐ¾Ð³Ð¾)
   */
  virtual void lab3();
  /**
   * ÐœÐµÑ‚Ð¾Ð´ Ð¿Ñ€Ð¾Ð³Ð¾Ð½ÐºÐ¸
   */
  virtual void lab4();
  /**
   * ÐœÐµÑ‚Ð¾Ð´ Ð¯ÐºÐ¾Ð±Ð¸
   */
  virtual void lab5();
  /**
   * ÐœÐµÑ‚Ð¾Ð´ Ð—ÐµÐ¹Ð´ÐµÐ»Ñ
   */
  virtual void lab6();
  /**
   * ÐžÐ´Ð¸Ð½ Ð¸Ð· Ð³Ñ€Ð°Ð´Ð¸ÐµÐ½Ñ‚Ð½Ñ‹Ñ… Ð¼ÐµÑ‚Ð¾Ð´Ð¾Ð²
   */
  bool logik(double *x,double *y,double e);
  double* um(double **x,double *y);
  double* v(double *x, double *y);
  double uc(double *x, double *y);
  double* umc( double *x,double y);
  virtual void lab7();
  double **t(double **x);
  double **um1(double **x,double **y);
  virtual void lab8();
};
