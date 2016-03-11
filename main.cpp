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

  l->read_file();
  l->run(atoi(argv[2]));
  l->write_result();
  l->check_result();
  delete l;
  return 0;
}


void print_usage()
{

}
