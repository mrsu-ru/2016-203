#include "PolyaevaEV.h"

/**
 * Метод Гаусса
 */
void PolyaevaEV::lab1()
{
  for (int k = 0; k < N; k++)
      for (int i = k; i < N; i++)
      {
          double temp = A[i][k];
          if (temp == 0) continue;
          for (int j = 0; j < N; j++) A[i][j] = A[i][j] / temp;
          b[i] = b[i] / temp;
          if (i == k)  continue;
          for (int j = 0; j < N; j++) A[i][j] = A[i][j] - A[k][j];
          b[i] = b[i] - b[k];
      }

  for (int k = N-1; k >= 0; k--)
  {
      x[k] = b[k];
      for (int i = 0; i < k; i++) b[i] = b[i] - A[i][k] * x[k];
  }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void PolyaevaEV::lab2()
{
  for (int k = 0; k < N; k++)
  	{
  		double max = abs(A[k][k]);
          int m_ind = k;
          for (int i = k+1; i < N; i++)
  		{
  			if (abs(A[i][k]) > max)
  			{
  				max = abs(A[i][k]);
  				m_ind = i;
  			}
  		}
  		for (int j = 0; j < N; j++) std::swap(A[k][j], A[m_ind][j]);
  		std::swap(b[k], b[m_ind]);

  		for (int i = k; i < N; i++)
  		{
  			double temp = A[i][k];
  			if (temp == 0) continue;
  			for (int j = 0; j < N; j++) A[i][j] = A[i][j] / temp;
  			b[i] = b[i] / temp;
  			if (i == k)  continue;
  			for (int j = 0; j < N; j++) A[i][j] = A[i][j] - A[k][j];
  			b[i] = b[i] - b[k];
  		}
  	}

  	for (int k = N-1; k >= 0; k--)
  	{
  		x[k] = b[k];
  		for (int i = 0; i < k; i++) b[i] = b[i] - A[i][k] * x[k];
  	}
}


/**
 * Метод квадратного корня (метод Холецкого)
 */
void PolyaevaEV::lab3()
{
  double temp, temp2;
  for (int i = 0; i < N; i++)
  {
      temp = 0.0; temp2 = 1;
      for (int k = 0; k < i; k++) temp += pow(A[k][i], 2);
      A[i][i] = sqrt(A[i][i] - (double)temp);

      if(i==0) temp2 = 0;
      else for(int l=i; l<N; l++) temp2 = temp2 * A[i-1][l];

      for (int j = 0; j < N; j++)
      {
          if (j < i) A[i][j] = 0;
          else if (i == j)  continue;
          else A[i][j] = (A[i][j] - temp2) / A[i][i];
      }
  }

  for (int i = 0; i < N; i++)
  {
      temp = 0;
      for (int k = 0; k < i; k++) temp = temp + A[k][i] * b[k];
      b[i] = (b[i] - temp) / A[i][i];
  }

  for (int k = N-1; k >= 0; k--)
  {
      double res = 0;
      for (int i = k+1; i < N; i++) res += A[k][i] * x[i];
      x[k] = (b[k] - res)/A[k][k];
  }
}

/**
 * Метод прогонки
 */
void PolyaevaEV::lab4()
{
    double* AA = new double[N];
    double* B = new double[N];

	  AA[0] = A[0][1]/(-A[0][0]);
    B[0] = b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        AA[i] = A[i][i+1]/(-A[i][i-1]*AA[i-1]-A[i][i]);
        B[i] = (-b[i] + A[i][i-1]*B[i-1])/(-A[i][i-1]*AA[i-1]-A[i][i]);
    }

    for(int i=N-1; i>=0; i--) x[i] = AA[i]*x[i+1]+B[i];

    delete[] AA;
    delete[] B;
}



/**
 * Метод Якоби
 */
void PolyaevaEV::lab5()
{
  double eps = 0.001;
	double* Y = new double[N];
	double norm;

	do {
		for (int i = 0; i < N; i++)
		{
			Y[i] = b[i];
			for (int k = 0; k < N; k++)
			{
				if (i != k) Y[i] -= A[i][k] * x[k];
			}
			Y[i] = Y[i]/A[i][i];
		}

        norm = fabs(x[0] - Y[0]);

		for (int i = 0; i < N; i++)
		{
			if (fabs(x[i] - Y[i]) > norm) norm = fabs(x[i] - Y[i]);
			x[i] = Y[i];
		}
	} while (norm > eps);

	delete[] Y;
}


/**
 * Метод Зейделя
 */

 void PolyaevaEV::zeroing(double *x)
 {
 	for (int i = 0; i < N; i++) x[i] = 0;
 }


void PolyaevaEV::lab6()
{
  	double norm, eps = 0.00001;
  	double* p = new double[N];
  	zeroing(x);

    do {
          for (int i = 0; i < N; i++) p[i] = x[i];
          for (int i = 0; i < N; i++)
          {
              double var = 0;
              for (int j = 0; j < i; j++) var += (A[i][j] * x[j]);
              for (int j = i + 1; j < N; j++) var += (A[i][j] * p[j]);
              x[i] = (b[i] - var) / A[i][i];
          }
          norm = 0;
          for (int i = 0; i < N; i++) norm += (x[i] - p[i])*(x[i] - p[i]);
      }
      while (sqrt(norm) >= eps);
      delete[] p;
}



/**
 * Метод минимальных невязок
 */

 double PolyaevaEV::multiplication_of_vectors(double *x, double *y)
 {
     double a = 0;
     for (int i = 0; i < N; i++) a += x[i]*y[i];
     return a;
 }

 void PolyaevaEV::difference(double* x, double *y, double *z)
 {
 	for (int i = 0; i < N; i++) x[i] = y[i] - z[i];
 }

 double* PolyaevaEV::multiplication_matrix_on_vector(double **A, double *y)
 {
      double *x = new double [N];
      double m = 0;
      for (int i = 0; i < N; i++)
         {
             for (int j = 0; j < N; j++) m += A[i][j]*y[j];
             x[i] = m; m = 0;
         }
      return x;
 }


void PolyaevaEV::lab7()
{
    double norm, eps = 0.0001;
    double* AP = new double[N];
    double* DIS = new double[N];
	  zeroing(x);
	  zeroing(AP);

    do {
		    double *TEMP = multiplication_matrix_on_vector(A, x);
		    difference(DIS, TEMP, b);

        double tau = multiplication_of_vectors(DIS, DIS);
		    double tempTau = multiplication_of_vectors(multiplication_matrix_on_vector(A, DIS), DIS);
		    tau = tau/tempTau;
		    if (tau != tau) tau = eps;

		    for (int i = 0; i < N; i++) TEMP[i] = DIS[i]*tau;
        difference(AP, AP, TEMP);

        norm = fabs(x[0] - AP[0]);
		    for (int i = 0; i < N; i++)
        {
			       if (fabs(x[i] - AP[i]) > norm) norm = fabs(x[i] - AP[i]);
			       x[i] = AP[i];
		    }
		   delete[] TEMP;
    } while (norm > eps);
	  delete[] AP;
	  delete[] DIS;
}



/**
 * Метод вращения (метод Якоби)
 */

 void PolyaevaEV::transposition(double **a, double **result)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = a[j][i];
        }
    }
}

void PolyaevaEV::multiplication(double **a, double **b, double **result)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
		{
            result[i][j] = 0;
			for(int k = 0; k < N; k++) result[i][j] += a[i][k] *b[k][j];
        }
}

void PolyaevaEV::lab8()
{
	double norm, eps = 0.0001;
	double** M = new double*[N];
	double** MT = new double*[N];
	double** AA = new double*[N];
	zeroing(x);

	for (int i = 0; i < N; i++)
	{
		AA[i] = new double[N];
		for (int j = 0; j < N; j++) AA[i][j] = 0;
	};

    do
	{
		int i_max = 0, j_max = 1;
		double max_el = abs(A[0][1]);

		for (int i = 0; i < N; i++)
			for (int j = i+1; j < N; j++)
				if (abs(A[i][j]) >= max_el) { max_el = abs(A[i][j]); i_max = i; j_max = j; };
		double phi = atan(2*max_el/(A[i_max][i_max] - A[j_max][j_max]))/2;

		for (int i = 0; i < N; i++) {
			M[i] = new double[N]; MT[i] = new double[N];
			for (int j = 0; j < N; j++) { MT[i][j] = 0; if(i == j) M[i][j] = 1; else M[i][j] = 0; };
		};
		M[i_max][i_max] = M[j_max][j_max] = cos(phi);
		M[i_max][j_max] = - sin(phi);
		M[j_max][i_max] = sin(phi);

		transposition(M, MT);
		multiplication(MT, A, AA);
		multiplication(AA, M, A);

    norm = 0;
    for (int i = 0; i < N; i++)
			  for (int j = i+1; j < N; j++) norm += pow(A[i][j],2);
    } while (sqrt(norm) > eps);
	for(int i = 0; i < N; i++) x[i] = A[i][i];

	delete[] M;
	delete[] MT;
	delete[] AA;
}
