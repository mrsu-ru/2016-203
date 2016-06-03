#include <cstdlib>
#include <cstring>
#include "lab.h"
#include "ArkunovIL.h"
#include "cheboksarovv.h"
#include "Chucmarevaki.h"
#include "godyaev.h"
#include "karchiganovaf.h"
#include "labushkinamn.h"
#include "lamaikinai.h"
#include "Levshtanoviv.h"
#include "Lysov.h"
#include "morozovns.h"
#include "nazarovvi.h"
#include "novikovdv.h"
#include "ploduhindm.h"
#include "PolkinAV.h"
#include "PolyaevaEV.h"
#include "sadovnikovev.h"
#include "Salnikov.h"
#include "Samylkin.h"
#include "Suharev.h"
#include "Sukhova.h"
#include "timovkin.h"
#include "Zelyunko.h"
#include <iostream>

void print_usage(char* name);


int main(int argc, char** argv)
{
  if (argc < 3) {
    print_usage(argv[0]);
    return 0;
  }

  lab *l = NULL;
  if (strcmp(argv[1], "arkunovil") == 0) {
    l = new ArkunovIL();
  }
  else if (strcmp(argv[1], "cheboksarovv") == 0) {
    l = new cheboksarovv();
  }
  else if (strcmp(argv[1], "chucmarevaki") == 0) {
    l = new Chucmarevaki();
  }
  else if (strcmp(argv[1], "godyaevav") == 0) {
    l = new godyaev();
  }
  else if (strcmp(argv[1], "karchiganovaf") == 0) {
    l = new karchiganovaf();
  }
  else if (strcmp(argv[1], "labushkinamn") == 0) {
    l = new labushkinamn();
  }
  else if (strcmp(argv[1], "lamaikinai") == 0) {
    l = new lamaikinai();
  }
  else if (strcmp(argv[1], "levshtanoviv") == 0) {
    l = new Levshtanoviv();
  }
  else if (strcmp(argv[1], "lysovvo") == 0) {
    l = new Lysov();
  }
  else if (strcmp(argv[1], "morozovns") == 0) {
    l = new morozovns();
  }
  else if (strcmp(argv[1], "nazarovvi") == 0) {
    l = new nazarovvi();
  }
  else if (strcmp(argv[1], "novikovdv") == 0) {
    l = new novikovdv();
  }
  else if (strcmp(argv[1], "ploduhindm") == 0) {
    l = new ploduhindm();
  }
  else if (strcmp(argv[1], "polkinav") == 0) {
    l = new PolkinAV();
  }
  else if (strcmp(argv[1], "polyaevaev") == 0) {
    l = new PolyaevaEV();
  }
  else if (strcmp(argv[1], "salnikovmd") == 0) {
    l = new Salnikov();
  }
  else if (strcmp(argv[1], "sadovnikovev") == 0) {
    l = new sadovnikovev();
  }
  else if (strcmp(argv[1], "samylkinsn") == 0) {
    l = new Samylkin();
  }
  else if (strcmp(argv[1], "suhareval") == 0) {
    l = new Suharev();
  }
  else if (strcmp(argv[1], "sukhovada") == 0) {
    l = new Sukhova();
  }
  else if (strcmp(argv[1], "timovkinsn") == 0) {
    l = new timovkin();
  }
  else if (strcmp(argv[1], "zelyunkona") == 0) {
    l = new Zelyunko();
  }
  else {
    print_usage(argv[0]);
    return 0;
  }

  l->read_file();
  l->run(atoi(argv[2]));
  l->write_result();
  l->check_result();

  delete l;
  return 0;
}


void print_usage(char* name)
{
  std::cout << "Usage:\n\n  " << name << " <fio> <lab_number>\n";
}
