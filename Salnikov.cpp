#include "Salnikov.h"


/**
* Метод Гаусса
*/
void Salnikov::lab1()
{
	long double tmp;
	for (int k = 0; k < N; k++) {
		for(int i = k+1; i < N; i++) {
			tmp = A[i][k]/A[k][k]; //  коэфицент умножения
			b[i] -= b[k]*tmp; 
			for(int j = 0 ; j < N; j++) {
				A[i][j] -= A[k][j]*tmp; //Приводим к вер. треугольной
			}
		}
	}

	for(int i = N-1; i >= 0; i--) {

		x[i] = b[i]/A[i][i];
		for(int j = i+1; j < N; j++) {
			x[i] += -A[i][j]*x[j]/A[i][i]; 
		}
	}


}

int Salnikov::maxElemNum(double* a, int c)
{
	int tmp = c;
	for (int i=c+1; i<N; i++) {
		if (abs(a[i]) > abs(a[tmp])) 
			tmp = i;
	}
	return tmp;
}
void Salnikov::lab2()
{
	double factor;
	double* column = new double[N];

	for (int k=0; k < N-1; k++) {
		for (int i=0; i<N; i++) 
			column[i] = A[i][k]; // выделяем колонку именно сдесь, на случай многократного использования
		
		int tmp_max_el_num = maxElemNum(column, k); //находим индекс максимального элемента в столбце
		
		if (tmp_max_el_num != k) {
			std::swap(A[tmp_max_el_num], A[k]);
			std::swap(x[tmp_max_el_num], x[k]);
			std::swap(b[tmp_max_el_num], b[k]);
		}
		
		for (int i = k+1; i < N; i++) {
			factor = A[i][k]/A[k][k];
			
			for (int j=k; j<N; j++)
				A[i][j] -= factor*A[k][j];
			
			b[i] -= factor*b[k];
		}
	}

	for(int i = 0; i<N; i++) 
		x[i]=b[i];

	for (int i=N-1;i>=0;i--) {
		
		for (int j=i+1;j<N;j++)
			x[i]-=A[i][j]*x[j];

		x[i] /= A[i][i];
	}
}


void Salnikov::lab3()
{

}

void Salnikov::lab4()
{

}

void Salnikov::lab5()
{

}

void Salnikov::lab6()
{

}

void Salnikov::lab7()
{

}


int main()
{
	Salnikov frst;
	frst.read_file();
	frst.run(1);
	frst.write_result();

	return 0;
}
