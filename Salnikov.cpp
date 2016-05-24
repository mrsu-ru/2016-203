#include "Salnikov.h"


/**
* Метод Гаусса
*/
void Salnikov::lab1() {
    double tmp;
    for (int i = 0; i < N; i++) {
        /*tmp = A[i][i];
        if (tmp != 0) {
            for (int j = N; j >= i; j--) {
                A[i][j] /= tmp;
                b[j] /= tmp;
            }
        }*/
        for (int j = i + 1; j < N; j++) {
            tmp = A[j][i]/A[i][i];
            if (tmp != 0) {
                for (int k = N; k >= i; k--)
                    A[j][k] -= tmp * A[i][k];
                b[j] -= tmp*b[i];
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

void Salnikov::lab2() {

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

void Salnikov::lab3() {
     double **L;
    L = new double*[N];
    for (int i = 0;  i < N; i++) {
        L[i] = new double[N];
        memset(L[i], 0, sizeof(double)*N);
    }
    double *y;
    y = new double[N];


    for (int i = 0; i < N; i++) {
        double sumikjk = 0;

        for (int j = 0; j < i; j++) { // поиск эл/ слева от диагонали
            sumikjk = 0;
            for (int k = 0; k < j; k++)
                sumikjk += L[i][k] * L[j][k];
            L[i][j] = (A[i][j] - sumikjk) / L[j][j];
        }

        sumikjk = 0;
        for (int k = 0; k < i; k++)
            sumikjk += L[i][k] * L[i][k];
        L[i][i] = sqrt(A[i][i] - sumikjk);

    }


    y[0] = b[0];
    for (int i = 1; i < N ; ++i) {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= y[j]*L[i][j];
        }
        y[i] /= L[i][i];
    }

    x[N - 1] = y[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < N; ++j)
            x[i] -= x[j] * L[j][i];
        x[i] /= L[i][i];
    }


    for (int i = 0; i < N; i++)
        delete[] L[i];
    delete[] L;
    delete[] y;
}

void Salnikov::lab4() {
    double *d, *c, *a; // верхняя, главная, нижняя
    d = new double[N];
    c = new double[N];
    a = new double[N];
    double m;

    a[0] = 0;
    d[N-1] = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i - 1 >= 0 && i - 1 < N) 
            d[i] = A[i-1][i];
        c[i] = A[i][i];
        if (i + 1 >= 0 && i + 1 < N) 
            a[i] = A[i+1][i];
    }  

    for (int i = 1; i < N; i++)
    {
        m = a[i]/c[i-1];
        c[i] = c[i] - m*d[i-1];
        b[i] = b[i] - m*b[i-1];
    }

    x[N-1] = b[N-1]/c[N-1];

    for (int i = N - 2; i >= 0; i--)
        x[i]=(b[i]-d[i]*x[i+1])/c[i];  

    delete[] b, c, d;
}

void Salnikov::lab5() {
    double eps = 0.0001;
    double* B = new double[N];
    double norma;

    do 
	{
        for (int i = 0; i < N; i++) {
            B[i] = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j)
                    B[i] -= A[i][j] * x[j];
            }
            B[i] /= A[i][i];
        }
        norma = abs(x[0] - B[0]);
        for (int j = 0; j < N; j++) {
            if (abs(x[j] - B[j]) > norma)
                norma = abs(x[j] - B[j]);
            x[j] = B[j];
        }
    } while (norma >= eps);
    delete[] B;

}

void Salnikov::lab6() {
    double eps = 0.0001;
    double* y = new double[N];
    double norma = 0;
     
    for (int i = 0; i < N; i++)
        x[i] = 0; //текущее решение
    do
    {
        for (int i = 0; i < N; i++)
            y[i] = x[i]; // предидущее решение

        for (int i = 0; i < N; i++)
        {
            double tmp = 0;
            norma = 0;
            
            for (int j = 0; j < i; j++)
                tmp += (A[i][j] * x[j]);
            
            for (int j = i + 1; j < N; j++)
                tmp += (A[i][j] * x[j]);
            
            x[i] = (b[i] - tmp) / A[i][i];
            
            for (int i = 0; i < N; i++)
                norma += abs(x[i] - y[i]);
        }
    } while (norma >= eps);

    delete[] y;
}

double **Salnikov::multiplication(double **a, double **b) 
{
    double **result;
    result = new double*[N];
    for (int i = 0; i < N; i++) {
        result[i] = new double[N];
        for (int j = 0; j < N; j++){
            result[i][j] = 0;
            for(int k = 0; k < N; k++)
                result[i][j] += a[i][k] *b[k][j];
        }
    }

    return result;
}

double **Salnikov::multiplication(double **a, double *b) 
{
    double **result;
    result = new double*[N];
    for (int i = 0; i < N; i++) {
        result[i] = new double[N];
        for (int j = 0; j < N; ++j)
            result[i][j] += a[i][j] * b[j];
    }

    return result;
}

double *Salnikov::multiplication(double *a, double **b) 
{
    double *result;
    result = new double[N];
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; ++j)
            result[i] += b[i][j] * a[j];
    }

    return result;
}

double **Salnikov::transposition(double **a) 
{
    double **result;
    result = new double*[N];
    for (int i = 0; i < N; ++i) {
        result[i] = new double[N];
        for (int j = 0; j < N; ++j) {
            result[i][j] = a[j][i];
        }
    }
    return result;
}

double *Salnikov::multiplication(double *a, double *b) 
{
    double *result;
    result = new double[N];
    for (int i = 0; i < N; ++i) {
        result[i] = a[i] + b[i];
    }
    return result;
}

double Salnikov::sum(double *a)
{
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += a[i];
    }
    return sum;
}

void Salnikov::lab7() 
{
    double *approximate, *discrepancy; //вектор приближений и вектор невязок
    approximate = new double[N];
    discrepancy = new double[N];

    for (int i = 0; i < N; ++i) {
        x[i] = 0;
        approximate[i] = 0;
        discrepancy[i] = 0;
    }

    double e = 0.00001, norma = 1;
    double *temp;
    temp = new double[N];

    do {
        temp = multiplication(x, A);
        for (int i = 0; i < N; ++i) {
            discrepancy[i] = (temp[i] - x[i]);
        }

        double tau;
        tau = sum(multiplication(discrepancy, discrepancy))/sum(multiplication(multiplication(discrepancy, A), discrepancy));
        if (tau != tau)
            tau = 0.0000000001;

        for (int i = 0; i < N; ++i) {
            temp[i] = discrepancy[i]*tau;
        }
        for (int i = 0; i < N; ++i) {
            approximate[i] = (approximate[i] - temp[i]);
        }

        norma = abs(x[0] - approximate[0]);
        for (int i = 0; i < N; ++i) {
            double ttmp = abs(x[i] - approximate[i]);
            if (ttmp > norma)
                norma = ttmp;
            x[i] = approximate[i];
        }
    } while (norma > e);

    delete[] approximate, discrepancy, temp;

}










