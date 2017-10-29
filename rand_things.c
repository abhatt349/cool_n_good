#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
//#include "rand_things.h"


int main () {
  umask(0);
  int f = open("/dev/random", O_RDWR);
  int arr[10];
  read(f,arr,sizeof(arr));
  close(f);
  printf("Reading file...\n\n");

  int i = 0;
  for(i; i<10;i++){
    printf("arr[%d]:  %d\n",i,arr[i]);
  }


  printf("\nWriting and reading new file...\n\n");
  int new = open("arrayhere",O_CREAT | O_WRONLY, 0666);
  write(new,arr,sizeof(arr));
  close(new);
  
  int arr2[10];
  new = open("arrayhere",O_RDONLY);  
  read(new,arr2,sizeof(arr2));
  close(new);

  i = 0;
  for(i; i<10;i++){
    printf("arr2[%d]:  %d\n",i,arr2[i]);
    }

  
  
  
  return 0;
}


