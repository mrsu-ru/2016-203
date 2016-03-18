#include <cstdlib>
#include <cstring>
#include "lab.h"
#include "cheboksarovv.h"
#include "karchiganovaf.h"
#include "Levshtanoviv.h"
#include "Lysov.h"
#include "morozovns.h"
#include "nazarovvi.h"
#include "ploduhindm.h"
#include "PolyaevaEV.h"
#include "Salnikov.h"
#include "Sukhova.h"
#include "Zelyunko.h"
#include <iostream>

void print_usage();


int main(int argc, char** argv)
{
  if (argc < 3) {
    print_usage();
    return 0;
  }

  lab *l = NULL;
  if (strcmp(argv[1], "cheboksarovv")) {
    l = new cheboksarovv();
  }
  if (strcmp(argv[1], "karchiganovaf")) {
    l = new karchiganovaf();
  }
  if (strcmp(argv[1], "levshtanoviv")) {
    l = new Levshtanoviv();
  }
  if (strcmp(argv[1], "lysovvo")) {
    l = new Lysov();
  }
  if (strcmp(argv[1], "morozovns")) {
    l = new morozovns();
  }
  if (strcmp(argv[1], "nazarovvi")) {
    l = new nazarovvi();
  }
  if (strcmp(argv[1], "ploduhindm")) {
    l = new ploduhindm();
  }
  if (strcmp(argv[1], "polyaevaev")) {
    l = new PolyaevaEV();
  }
  if (strcmp(argv[1], "salnikovmd")) {
    l = new Salnikov();
  }
  if (strcmp(argv[1], "sukhovada")) {
    l = new Sukhova();
  }
  if (strcmp(argv[1], "zelyunkona")) {
    l = new Zelyunko();
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
  std::cout << "Usage:\n\n  vvm fio lab_number\n";
}
