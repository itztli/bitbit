#include <stdio.h>
#include <stdlib.h>

int main(int argn, char **argv){
  char *mystring;
  // printf("%s\n",argv[1]);
  
  if (argn < 2){
    printf("Error: You need pass an argument.\n");
    return 0;
  }
  
  mystring = malloc(sizeof(argv[1]));
  sprintf(mystring,"%s",argv[1]);
  printf("%s\n",mystring);
  return 1;
}
