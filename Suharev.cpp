#include "Suharev.h"

/**
 * Метод Гаусса
 */
void Suharev::lab1()
{
  int i,j,k;
  double y;
    for (k=0;k<N;k++)
    {
        for(i=k+1;i<N;i++)
        {
            y=A[i][k]/A[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<N;j++)
            {
                A[i][j]-=A[k][j]*y;
            }
        }
    }

    for(i=N-1;i>=0;i--)
    {
        x[i]=b[i]/A[i][i];
        for(j=i+1;j<N;j++)
        {
            x[i]+=-A[i][j]*x[j]/A[i][i];
        }
    }
}

/**
 * Метод Гаусса с выбором главного элемента
 */
void Suharev::lab2()
{
    for (int k = 0; k < N; ++k) {
        int string_id_of_max_el = -1;
        double max_el = 0;

        // Find id of string of max element
        for (int p = 0; p < N; ++p) {
            if (std::abs(A[k][p]) >= max_el) {
                max_el = std::abs(A[k][p]);
                string_id_of_max_el = p;
            }
        }

        //
        if (string_id_of_max_el != -1) {
            for (int j = 0; j < N; ++j) {
                std::swap(A[j][string_id_of_max_el], A[j][k]);
            }
            std::swap(b[string_id_of_max_el], b[k]);

            for (int i = k+1; i < N; ++i)
            {

                double koef = A[i][k]/(A[k][k]*1.0);
                for (int j = k; j < N; ++j)
                    A[i][j] -= koef*A[k][j];
                b[i] -= koef*b[k];
            }

        }

    }


    x[N - 1] = b[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < N; ++j)
            x[i] -= x[j] * A[i][j];
        x[i] /= A[i][i];
    }
}

/**
 * Метод квадратного корня (метод Холецкого)
 */
void Suharev::lab3()
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
void Suharev::lab4()
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
void Suharev::lab5()
{
    long double eps = 0.0001;
    long double* p = new long double[N];
    long double norm;
    for (int i = 0; i < N; i++)
        x[i]=0;
    do {
        for (int i = 0; i < N; i++)
        {
            p[i] = b[i];
            for (int j = 0; j < N; j++)
                if (i != j) p[i] -= A[i][j] * x[j];
            p[i] /= A[i][i];
        }
        norm = fabs(x[0] - p[0]);
        for (int h = 0; h < N; h++)
        {
            if (fabs(x[h] - p[h]) > norm)
                norm = fabs(x[h] - p[h]);
            x[h] = p[h];
        }
    } while (norm > eps);
    delete[] p;
}

/**
 * Метод Зейделя
 */
void Suharev::lab6()
{
    long double eps = 0.0001;
    long double* y = new long double[N];
    long double norm = 0;
    long double var = 0;

    for (int i = 0; i < N; i++)
            x[i] = 0;
    do
    {
        for (int i = 0; i < N; i++)
            y[i] = x[i];

        for (int i = 0; i < N; i++)
        {
            var = 0;
            norm = 0;
            for (int j = 0; j < i; j++)
                var += (A[i][j] * x[j]);
            for (int j = i + 1; j < N; j++)
                var += (A[i][j] * x[j]);
            x[i] = (b[i] - var) / A[i][i];
            for (int i = 0; i < N; i++)
                norm += (x[i] - y[i])*(x[i] - y[i]);
        }
    } while (sqrt(norm) >= eps);

    delete[] y;
}


/**
 * Один из градиентных методов
 */
void Suharev::lab7()
{

}
