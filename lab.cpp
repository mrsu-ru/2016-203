#include "lab.h"
#include <cstdlib>

void lab::read_file() {}
void lab::run(int lab_number) {}
void lab::write_result() {}
void lab::check_result() {}


/**
 *
 */
void lab::init(int N, double **A, double *b, double *x)
{
  this->A = A;
  this->b = b;
  this->x = x;

  this->N = N;
}

lab::~lab()
{
  if (A != NULL) {
    for (int i = 0; i < N; i++) {
      if (A[i] != NULL) {
        delete[] A[i];
      }
    }
    delete[] A;
  }
  if (b != NULL) {
    delete[] b;
  }
  if (x != NULL) {
    delete[] x;
  }
}
