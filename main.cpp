#include <cstdlib>
#include <cstring>
#include "lab.h"
#include "ivanovii.h"

void print_usage();


int main(int argc, char** argv)
{
  if (argc < 3) {
    print_usage();
    return 0;
  }

  lab *l = NULL;
  if (strcmp(argv[1], "ivanovii")) {
    l = new ivanovii();
  }
  if (strcmp(argv[1], "petrovii")) {
    l = new ivanovii();
  }
  else {
    print_usage();
    return 0;
  }

<<<<<<< HEAD
  l->read_file();
=======
  int n = 100;
  double **a = new double*[n];
  double *b = new double[n];
  double *x = new double[n];
  for (int i= 0; i < n; i++) {
    a[i] = new double[n];
  }

  l->init(n, a, b, x);

  for (int i = 1; i < n-1; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i-1) {
        a[i][j] = 1.0;
      }
      else if (j == i) {
        a[i][j] = -2.0;
      }
      else if (j == i+1) {
        a[i][j] = 1.0;
      }
      else {
        a[i][j] = 0.0;
      }
    }
  }

>>>>>>> 3a8c61df8cd3f1ab5951bd0b2ec046253441e36c
  l->run(atoi(argv[2]));
  l->write_result();
  l->check_result();
  delete l;
  return 0;
}


void print_usage()
{

}
