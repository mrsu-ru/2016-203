#include "timovkin.h"

/**
 * ����� ������
 */
void timovkin::lab1()
{
double p;
for (int i = 0; i<N; i++)
for (int k=i+1;k<N;k++)
{
p=A[k][i]/A[i][i];
b[k]=b[k]-b[i]*p;
for (int j=0;j<N;j++)
A[k][j]=A[k][j]-A[i][j]*p;
}
for (int i = N-1; i>=0; i--)
for (int k=i-1;k>=0;k--)
{
p=A[k][i]/A[i][i];
b[k]=b[k]-b[i]*p;
for (int j=N-1;j>=0;j--)
A[k][j]=A[k][j]-A[i][j]*p;
}
for (int j = 0; j<N; j++)
x[j]=b[j]/A[j][j];
}


/**
 * ����� ������ � ������� �������� ��������
 */
void timovkin::lab2()
{
    // for (int i = 0; i < N; i++)
    //     x[i] = b[i];
    // double m,temp;
    //  int ii;
    //  for (int k = 0; k < N-1; k++)
    //     {
    //         ii = k;
    //         for (int i=k+1; i<N; i++)
    //             if(abs(A[i][k]) > abs(A[ii][k])) ii = i;
    //             temp=A[ii];
    //             A[k]=A[ii];
    //             A[k]=temp;
    //             temp=0;
    //
    //             temp=b[ii];
    //             b[k]=b[ii];
    //             b[k]=temp;
    //          for (int i = k+1; i < N; i++)
    //          {
 	// 			m = A[i][k] / A[k][k];
  	// 			for (int j = k; j < N; j++)
    //             {
  	// 				A[i][j]-=m * A[k][j];
  	// 			}
    //              x[i]-=m * x[k];
    //
    //          }
    //     }
    //
    // for (int i=N-1;i>=0;i--)
    // {
    //     for (int j=i+1;j<N;j++)
    //             x[i]-=A[i][j]*x[j];
    //     x[i]/=A[i][i];
    // }
}

/**
 * ����� ����������� ����� (����� ���������)
 */
void timovkin::lab3()
{
// for(int i=0; i<N; i++){
// 		double s=0.0;
// 		for(int j=0; j<i-1; j++)
//             {
// 			s+=l[i][j]*l[i][j];
// 		}
// 		l[i][i]=sqrt(A[i][i]-s);
// 		s=0.0;
// 		for(int k=i; k<N; k++){
// 			for(int j=0; j<i-1; j++){
// 				s+=l[k][j]*l[i][j];
// 			}
// 			l[k][i]=(A[k][i]-s)/l[i][i];
// 		}
// 	}
// 	for(int i=0; i<N; i++){
// 		double s = 0.0;
// 		for(int j=0; j<i; j++){
// 			s += l[i][j]*y[j];
//
// 		}
// 		y[i]=(f[i]-s)/l[i][i];
// 	}
// 	for(int i=0; i<N; i++){
// 		for(int j=0; j<i; j++){
// 			std::swap(l[i][j], l[j][i]);
// 		}
// 	}
//    for(int i=N-1; i>=0; i--){
// 		double s = 0.0;
// 		for(int j=i+1; j<N; j++){
// 			s += l[i][j]*x[j];
// 		}
// 		x[i]=(y[i]-s)/l[i][i];
// 	}
//
}



/**
 * ����� ��������
 */
void timovkin::lab4()
{

}



/**
 * ����� �����
 */
void timovkin::lab5()
{

}



/**
 * ����� �������
 */
void timovkin::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void timovkin::lab7()
{

}
