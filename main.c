#include <stdio.h>
#include <stdlib.h>
#include "bit.h"

/*
Modificar el codigo para que mediante la linea de argumentos les pasen la cantidad de espacios a asignar en la memoria RAM y dentro del programa reserven esa N cantidad de enteros en la variable mypointer y a traves de un for asignen valores secuenciales de 0 a N y los imprima.
*/


int main(int argn, char **argv){
  char c; // 1 byte = 8 bits
  int i;  // 4 bytes = 32 bits
  double d; // 8 bytes = 64 bits

  c = 0x01; //''; //BIG 1000 0000   LIT 0000 0001
  i = 1024;
  d = 3.1416;

  //printf("%i\t%i\t%le\n",c,i,d);

  print_bit(c);

  

//  char *mystring;
//  int *mypointer;
//  // printf("%s\n",argv[1]); 
//  if (argn < 2){
//    printf("Error: You need pass an argument.\n");
//    return 0;
//  }
//  mystring = malloc(1024);        //sizeof(argv[1]));
//  sprintf(mystring,"%s",argv[1]);
//  printf("%s\n",mystring);
//  printf("%p\n",&mystring);
//  free(mystring);
  return 1;
}
