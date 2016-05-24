#pragma once
#include "lab.h"
#include <cmath>
#include <algorithm>

class Salnikov: public lab
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
	double **multiplication(double **a, double **b);
	double **multiplication(double **a, double *b);
	double *multiplication(double *a, double **b);
	double *multiplication(double *a, double *b);
	double **transposition(double **a);
	double sum(double *a);
	virtual void lab7();
};
