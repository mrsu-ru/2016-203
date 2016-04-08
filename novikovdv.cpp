#include "novikovdv.h"

/**
 * Метод Гаусса
 */
void novikovdv::lab1()
{
 double t=0;
    for(int k=0; k<N; k++)
        {
            for(int i=k+1; i<N; i++)
                {
                    t=A[i][k]/A[k][k];
                    b[i]-=t*b[k];

                    for (int j=0; j<N; j++)
                        A[i][j]-=t*A[k][j];
                }
        }

        for(int i=N-1; i>=0; i--)
        {
            t=0;
            for(int j=i+1; j<N; j++)
            t+=A[i][j]*x[j];
            x[i]=(b[i]-t)/A[i][i];
        }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void novikovdv::lab2()
{

    double t=0;
    for(int k=0; k<N; k++)
        {
            double max_el=abs(A[k][k]);  //Замена строк
            int max_id=k;
            for (int i=k+1; i<N; i++)
                {
                    if (abs(A[i][k]) > max_el)
                        {
                            max_el=abs(A[max_id][k]);
                            max_id=i;
                        }
                }
             for (int j=0; j<N; j++)
                std::swap(A[k][j], A[max_id][j]);
                std::swap(b[k], b[max_id]);


        for(int i=k+1; i<N; i++)
            {
                t=A[i][k]/A[k][k];
                b[i]-=t*b[k];

                for (int j=0; j<N; j++)
                    A[i][j]-=t*A[k][j];

            }
        }

        for(int i=N-1; i>=0; i--)
        {
            t=0;
            for(int j=i+1; j<N; j++)
            t+=A[i][j]*x[j];
            x[i]=(b[i]-t)/A[i][i];
        }

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void novikovdv::lab3()
{

}



/**
 * Метод прогонки
 */
void novikovdv::lab4()
{

}



/**
 * Метод Якоби
 */
void novikovdv::lab5()
{

}



/**
 * Метод Зейделя
 */
void novikovdv::lab6()
{

}



/**
 * Один из градиентных методов
 */
void novikovdv::lab7()
{

}
