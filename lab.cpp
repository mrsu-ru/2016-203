#include "lab.h"

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
