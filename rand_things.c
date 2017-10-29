#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
//#include "rand_things.h"

int * data = NULL;

int main () {
  int f = open("/dev/random", O_RDWR);
  data = (int*)malloc(1000);
  int *origin = data;
  read(f,data,1000);
  close(f);
  
  printf("%d\n", rand_gen());
  free(origin);
  
  
  
  
  return 0;
}


int rand_gen () {
  int ret = *data;
  data++;
  return ret;
}
