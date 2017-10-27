#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
//#include "rand_things.h"

int main () {
  printf("%d\n", rand_gen(8));
  
  
  
  return 0;
}


int rand_gen (int b) {
  int f = open("/dev/random", O_RDWR);
  int* toret;
  read(f, toret, b);
  close(f);
  return *toret;
}
