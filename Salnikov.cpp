#include "Salnikov.h"


/**
* Метод Гаусса
*/
void Salnikov::lab1() {
    long double tmp;
    for (int i = 0; i < N; i++) {
        tmp = A[i][i];
        if (tmp != 0) {
            for (int j = N; j >= i; j--) {
                A[i][j] /= tmp;
                b[j] /= tmp;
            }
        }
        for (int j = i + 1; j < N; j++) {
            tmp = A[j][i];
            if (tmp != 0) {
                for (int k = N; k >= i; k--)
                    A[j][k] -= tmp * A[i][k];

            }
        }
    }

    x[N - 1] = b[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < N; ++j)
            x[i] -= x[j] * A[i][j];
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
    }

}

void Salnikov::lab3() {

}

void Salnikov::lab4() {

}

void Salnikov::lab5() {

}

void Salnikov::lab6() {

}

void Salnikov::lab7() {

}
