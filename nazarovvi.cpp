#include "nazarovvi.h"

/**
 * ����� ������
 */
void nazarovvi::lab1()
{
    double coef = 0;
    for (int k=0; k<N-1; k++)
    {
        for (int i=k+1; i<N; i++)
        {
            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
            {
                A[i][j] -= coef*A[k][j];
               // if (abs(A[i][j])<1e-16) A[i][j] = 0;
            }
            b[i] -= coef*b[k];
        }
    }
    for(int i = 0; i<N; i++)
        x[i]=b[i];

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }

}


/**
 * ����� ������ � ������� �������� ��������
 */
 int nazarovvi::maxElemNum(long double* a, int c)
    {
        int tmp = c;
        for (int i=c+1; i<N; i++)
        {
            if (fabs(a[i]) > fabs(a[tmp])) tmp = i;
        }
        return tmp;
    }
void nazarovvi::lab2()
{
    long double coef;
    long double* column = new long double[N];

    for (int k=0; k<N-1; k++)
    {
        for (int i=0; i<N; i++)
            {
                column[i] = A[i][k];
            }
        if (maxElemNum(column,k) != k)
            {
                std::swap(A[maxElemNum(column,k)], A[k]);
                std::swap(b[maxElemNum(column,k)], b[k]);
            }
        for (int i=k+1; i<N; i++)
        {

            coef = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= coef*A[k][j];
            b[i] -= coef*b[k];
        }

    }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];

    }


}



/**
 * ����� ����������� ����� (����� ���������)
 */
void nazarovvi::lab3()
{

}



/**
 * ����� ��������
 */
void nazarovvi::lab4()
{

}



/**
 * ����� �����
 */
void nazarovvi::lab5()
{

}



/**
 * ����� �������
 */
void nazarovvi::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void nazarovvi::lab7()
{

}
