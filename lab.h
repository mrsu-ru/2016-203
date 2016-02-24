#pragma once


class lab
{
public:
  void read_file();
  void run(int lab_number);
  void write_result();
  void check_result();
protected:
  int N;
  double **A, *b, *x;

  /**
   * Метод Гаусса
   */
  virtual void lab1() = 0;
  /**
   * Метод Гаусса с выбором главного элемента
   */
  virtual void lab2() = 0;
  /**
   * Метод квадратного корня (метод Холецкого)
   */
  virtual void lab3() = 0;
  /**
   * Метод прогонки
   */
  virtual void lab4() = 0;
  /**
   * Метод Якоби
   */
  virtual void lab5() = 0;
  /**
   * Метод Зейделя
   */
  virtual void lab6() = 0;
  /**
   * Один из градиентных методов
   */
  virtual void lab7() = 0;
}
