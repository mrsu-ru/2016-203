#include "lab.h"
#include <fstream>
#include <iostream>

void lab::read_file()
{
	std::fstream ina("matrix_A.txt", std::fstream::in); // Матрица А и В хранятся в файлах matrix_A.txt 
	std::fstream inb("matrix_B.txt", std::fstream::in);	// и matrix_b.txt соответственно, в matrix_A.txt 
														// первое число это размер матрицы - N
	
	ina >> N;

	A = new double*[N];
	for (int i = 0; i < N; ++i) {
		A[i] = new double[N];
	}
	b = new double[N];
	x = new double[N];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ina >> A[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		inb >> b[i];
		x[i] = 0;
	}

	ina.close();
	inb.close();
}

void lab::run(int lab_number)
{
	switch (lab_number)
	{
	case 1:
		this->lab1();
		break;
	case 2:
		this->lab2();
		break;
	case 3:
		this->lab3();
		break;
	case 4:
		this->lab4();
		break;
	case 5:
		this->lab5();
		break;
	case 6:
		this->lab6();
		break;
	case 7:
		this->lab7();
		break;
	default:
		break;
	}
}
void lab::write_result() 
{
	for (int i = 0; i < N; ++i) {
		std::cout << x[i] << std::endl;
	}
}
void lab::check_result() {}